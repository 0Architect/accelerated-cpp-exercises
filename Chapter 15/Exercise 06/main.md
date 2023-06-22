class Picture;

class Pic_base {
    friend std::ostream& operator<<(std::ostream&, const Picture&);
    friend class Frame_Pic;
    friend class HCat_Pic;
    friend class VCat_Pic;
    friend class String_Pic;

    // no public interface
    typedef Vec<Str>::size_type ht_sz;
    typedef Str::size_type wd_sz;

    // this class is an abstract base class
    virtual wd_sz width() const = 0;
    virtual ht_sz height() const = 0;
    virtual void display(std::ostream&, ht_sz, bool) const = 0;

protected:
    static void pad(std::ostream& os, wd_sz, wd_sz);
};

class Picture {
    friend std::ostream& operator<<(std::ostream&, const Picture&);
    friend Picture frame(const Picture&);
    friend Picture hcat(const Picture&, const Picture&);
    friend Picture vcat(const Picture&, const Picture&);

public:
    Picture(const Vec<Str>& = Vec<Str>());

private:
    Picture(Pic_base* ptr) : p(ptr) {}

    Ptr<Pic_base> p;
};

Picture::Picture(const Vec<Str>& v) : p(new String_Pic(v)) {}

std::ostream& operator<<(std::ostream& os, const Picture& picture) {
    const Pic_base::ht_sz ht = picture.p->height();
    for (Pic_base::ht_sz i = 0; i != ht; ++i) {
        picture.p->display(os, i, false);
        os << std::endl;
    }
    return os;
}

class String_Pic : public Pic_base {
    friend class Picture;
    Vec<Str> data;

    String_Pic(const Vec<Str>& v) : data(v) {}

    ht_sz height() const { return data.size(); }
    wd_sz width() const;
    void display(std::ostream&, ht_sz, bool) const;
};

wd_sz String_Pic::width() const {
    wd_sz n = 0;
    for (ht_sz i = 0; i != data.size(); ++i)
        n = std::max(n, data[i].size());
    return n;
}

void String_Pic::display(std::ostream& os, ht_sz row, bool do_pad) const {
    wd_sz start = 0;
    // write the row if we're still in range
    if (row < height()) {
        os << data[row];
        start = data[row].size();
    }
    // pad the output if necessary
    if (do_pad)
        pad(os, start, width());
}

void Pic_base::pad(std::ostream& os, wd_sz beg, wd_sz end) {
    while (beg != end) {
        os << " ";
        ++beg;
    }
}

Picture frame(const Picture& pic) {
    return new Frame_Pic(pic.p);
}

Picture hcat(const Picture& l, const Picture& r) {
    return new HCat_Pic(l.p, r.p);
}

Picture vcat(const Picture& t, const Picture& b) {
    return new VCat_Pic(t.p, b.p);
}

class Frame_Pic : public Pic_base {
    friend Picture frame(const Picture&);
    Ptr<Pic_base> p;
    Str::size_type fwidth;

    Frame_Pic(const Ptr<Pic_base>& pic, char c = '*')
        : p(pic), fwidth(pic->width() + 4), frame_char(c) {}

    wd_sz width() const { return p->width() + 4; }
    ht_sz height() const { return p->height() + 4; }
    void display(std::ostream&, ht_sz, bool) const;

private:
    char frame_char;
};

void Frame_Pic::display(std::ostream& os, ht_sz row, bool do_pad) const {
    if (row >= height()) {
        // out of range
        if (do_pad)
            pad(os, 0, width());
    } else {
        if (row == 0 || row == height() - 1) {
            // top or bottom row
            os << Str(fwidth, frame_char);
        } else if (row == 1 || row == height() - 2) {
            // second from top or bottom row
            os << frame_char;
            pad(os, 1, fwidth - 1);
            os << frame_char;
        } else {
            // interior row
            os << frame_char << " ";
            p->display(os, row - 2, true);
            os << " " << frame_char;
        }
    }
}

class HCat_Pic : public Pic_base {
    friend Picture hcat(const Picture&, const Picture&);
    Ptr<Pic_base> left, right;

    HCat_Pic(const Ptr<Pic_base>& l, const Ptr<Pic_base>& r)
        : left(l), right(r) {}

    wd_sz width() const { return left->width() + right->width(); }
    ht_sz height() const { return std::max(left->height(), right->height()); }
    void display(std::ostream&, ht_sz, bool) const;
};

void HCat_Pic::display(std::ostream& os, ht_sz row, bool do_pad) const {
    wd_sz left_width = left->width();
    wd_sz right_width = right->width();
    wd_sz total_width = left_width + right_width;

    if (row < left->height()) {
        // Display left picture row
        left->display(os, row, do_pad || row < right->height());
        if (do_pad && right_width > left_width)
            pad(os, left_width, total_width);
    } else if (row < height()) {
        // Display right picture row
        right->display(os, row - left->height(), do_pad);
        if (do_pad && left_width > right_width)
            pad(os, right_width, total_width);
    }
}

class VCat_Pic : public Pic_base {
    friend Picture vcat(const Picture&, const Picture&);
    Ptr<Pic_base> top, bottom;

    VCat_Pic(const Ptr<Pic_base>& t, const Ptr<Pic_base>& b)
        : top(t), bottom(b) {}

    wd_sz width() const { return std::max(top->width(), bottom->width()); }
    ht_sz height() const { return top->height() + bottom->height(); }
    void display(std::ostream&, ht_sz, bool) const;
};

void VCat_Pic::display(std::ostream& os, ht_sz row, bool do_pad) const {
    wd_sz w = 0;
    if (row < top->height()) {
        // we are in the top subpicture
        top->display(os, row, do_pad);
        w = top->width();
    } else if (row < height()) {
        // we are in the bottom subpicture
        bottom->display(os, row - top->height(), do_pad);
        w = bottom->width();
    }
    if (do_pad)
        pad(os, w, width());
}

Picture reframe(const Picture& pic, char corner = '+', char hborder = '-', char vborder = '|') {
    Picture framed = pic;
    Ptr<Pic_base> p = framed.p;
    if (p->height() > 2 && p->width() > 2) {
        Ptr<Pic_base> new_p = new Frame_Pic(p, corner, hborder, vborder);
        framed.p = new_p;
    }
    return framed;
}

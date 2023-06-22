class Frame_Pic : public Pic_base {
    friend Picture frame(const Picture&);
    Ptr<Pic_base> p;
    char corner;
    char hborder;
    char vborder;

    Frame_Pic(const Ptr<Pic_base>& pic, char c = '*', char h = '*', char v = '*')
        : p(pic), corner(c), hborder(h), vborder(v) {}

    wd_sz width() const { return p->width() + 4; }
    ht_sz height() const { return p->height() + 4; }
    void display(std::ostream&, ht_sz, bool) const;
};

void Frame_Pic::display(std::ostream& os, ht_sz row, bool do_pad) const {
    if (row >= height()) {
        // out of range
        if (do_pad)
            pad(os, 0, width());
    } else {
        if (row == 0 || row == height() - 1) {
            // top or bottom row
            os << std::string(width(), hborder);
        } else if (row == 1 || row == height() - 2) {
            // second from top or bottom row
            os << hborder;
            pad(os, 1, width() - 1);
            os << hborder;
        } else {
            // interior row
            os << vborder << " ";
            p->display(os, row - 2, true);
            os << " " << vborder;
        }
    }
}

Picture frame(const Picture& pic, char corner = '*', char hborder = '*', char vborder = '*') {
    return new Frame_Pic(pic.p, corner, hborder, vborder);
}

class HCat_Pic : public Pic_base {
    // ...

public:
    // ...

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

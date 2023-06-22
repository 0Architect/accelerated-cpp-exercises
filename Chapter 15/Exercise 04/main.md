class Picture {
    // ...

public:
    // ...

    void reframe(char corner = '*', char hborder = '*', char vborder = '*') {
        p.make_unique();
        if (Frame_Pic* fp = dynamic_cast<Frame_Pic*>(p.get()))
            fp->reframe(corner, hborder, vborder);
    }
};

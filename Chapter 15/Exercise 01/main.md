int main() {
    // Some initial starting picture
    Picture p(std::vector<std::string>{"Hello", "World!"});

    Picture q = frame(p);
    Picture r = hcat(p, q);
    Picture s = vcat(q, r);

    Picture result = frame(hcat(s, vcat(r, q)));

    std::cout << result << std::endl;

    return 0;
}

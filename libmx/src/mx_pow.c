double mx_pow(double n, unsigned int pow) {
    double rslt = (n > 0) ? 1 : 0;

    if (n > 0) {
        for (unsigned i = 0; i < pow; i++) {
            rslt *= n;
        }
    }

    return rslt;
}

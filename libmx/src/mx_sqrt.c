int mx_sqrt(int x) {
    int result;
    int mult;

    for (result = 1; result <= 46341; result++ ) {
        mult = result * result;
        
        if (mult == x)
            return result;
        if( mult > x || result == 46341) {
            return 0;
        }
    }

    return 0;
}

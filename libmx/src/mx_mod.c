unsigned long mx_mod(int num) {
	unsigned long result = (num < 0) ? (unsigned long)num * -1 : num;
	
	return (unsigned long)result;
}

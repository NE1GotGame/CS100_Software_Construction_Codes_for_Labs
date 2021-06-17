int main() {
	int *p = new int(10);
	int *ip = p + 2;

	delete p;
	delete p;

    return 0;
}

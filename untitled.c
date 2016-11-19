int main(void){
	char *cat[] = {"Hello", "World!","test","me"};
	//int num[] = {1, 2, 3, 4, 5};
	int i;
	for(i=0; i<sizeof(cat)/sizeof(cat[0]); i++){
		printf("%s ", cat[i]);
	}
	return 0;
}
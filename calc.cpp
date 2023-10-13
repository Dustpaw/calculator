#include"calc_function.cpp"
void print_help() {  
	printf("\nHelp Information for sum:\n");  
	printf("Usage: lumda\n");  
	printf("Sum and prints the result.\n");  
	printf("Please don't enter wrong lumda,make sure no extra blank included\n");
}
int main(){
	const char* result_file_name = "results.txt";
	ofstream file(result_file_name);  
	rl_initialize();
	char *input;
	while((input = readline("a+b> ")) != nullptr){
		if(input==NULL) break;
		if(!strcmp(input,"quit")){
			break;
		}
		if(!strcmp(input,"help")){
			print_help();
			free(input);
			continue;
		}
		int result = work_f(input);  
		cout<<result<<endl;
	file << input << " = " << result << endl;  
		add_history(input);
		free(input);
	}
	file.close(); // Close the results file  
	free(input);
	return 0;
}

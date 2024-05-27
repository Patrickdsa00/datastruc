struct run{
	float distance;
	int hour, minute;
}typedef Run;

struct runner{
	int num_runs;
	char gender;
	Run * run_arr;
}typedef Runner;

void get_runner(Runner * runner);
void init_runner(Runner * runner, int num_runs);
void print_runner(Runner * runner);
float pace_per_run(Runner * runner, int index);
void final_stat(Runner * runner);


#include "dolphin_tests.h"
#include <iostream>
#include <string>
#include <sstream>
#include <cassert>
#include <array>
#include <fstream>
#include <vector>
#include <sys/stat.h> // For stat()


// forward declaration 
// this is to read the output of the executable with popen
uint8_t run_command_and_check_output(const std::string& command_to_exec, std::ostringstream& result);


// Utility function to read the log file into a vector of strings
std::vector<std::string> read_log_file(const std::string& file_path) {
    std::vector<std::string> lines;
    std::ifstream file(file_path);
    std::string line;
    while (std::getline(file, line)) {
        lines.push_back(line);
    }
    return lines;
}

// Utility function to remove the timestamp from a log line
std::string remove_timestamp(const std::string& line) {
    size_t pos = line.find(']');
    if (pos != std::string::npos) {
        return line.substr(pos + 1);
    }
    return line; // Return the original line if no timestamp is found
}

// Utility function to check if a file exists
bool file_exists(const std::string& file_path) {
    struct stat buffer;
    return (stat(file_path.c_str(), &buffer) == 0);
}


// test function to compare output with log file content
const char* test_account() {
    std::ostringstream result;

	// this is my executable
    std::string arg = "../theJobOfYourDreams";
	if (!file_exists(arg)) {
		std::cerr << "File not found: " << arg << std::endl;
		return "error file not found"; 
	}
    uint8_t exit_status = run_command_and_check_output(arg, result);
	
	// this is the orig logfile to check against
	std::string file_path = "19920104_091532.log";
	// does it exists?
	if (!file_exists(file_path)) {
		std::cerr << "File not found: " << file_path << std::endl;
		return "error file not found"; 
	}
    // Read the log file
    std::vector<std::string> log_lines = read_log_file(file_path);

    // Split the command output into lines
    std::vector<std::string> output_lines;
    std::istringstream iss(result.str());
    std::string output_line;
    while (std::getline(iss, output_line)) {
        output_lines.push_back(output_line);
    }

    // Compare the number of lines
	debug("log_lines.size(): %lu", log_lines.size());
	debug("output_lines.size(): %lu", output_lines.size());
	my_assert(log_lines.size() == output_lines.size(), "line count is different\n");
    
	// compare line by line ignoring the timestamp in the log lines and the command output
	for (size_t i = 0; i < log_lines.size() && i < output_lines.size(); ++i) {
		if (remove_timestamp(log_lines[i]) != remove_timestamp(output_lines[i])) {
			debug("log_lines[%lu]: %s", i, log_lines[i].c_str());
			debug("output_lines[%lu]: %s", i, output_lines[i].c_str());
		}

		my_assert(remove_timestamp(log_lines[i]) == remove_timestamp(output_lines[i]), "lines are different\n");
    }

    my_assert(exit_status == 0, "exit status is not 0\n");
    return NULL;
}

const char *all_tests()
{
	// necessary to start the test suite
	suite_start();
	
	// run the tests
	run_test(test_account);	
	
	return NULL;
}

// works as a main
RUN_TESTS(all_tests);

/*
	I used this already in minishell... now modified to just use bash and the name of my executable
*/
uint8_t run_command_and_check_output(const std::string& command_to_exec, std::ostringstream& result) 
{
    debug("running test_popen\n");
    fflush(stdout);

    std::string command = "bash -c \"" + command_to_exec + "\"";
    FILE *fp = popen(command.c_str(), "r");
    if (fp == NULL) {
        perror("popen");
        return false;
    }

    std::array<char, 128> buffer;
    while (fgets(buffer.data(), buffer.size(), fp) != NULL) {
        result << buffer.data();
    }

  	int status = pclose(fp);
    if (status == -1) {
        perror("pclose");
        return 1; // Error code for pclose failure
    } else {
        if (WIFEXITED(status)) {
            uint8_t exit_status = WEXITSTATUS(status);
            // printf("Exit status: %d\n", exit_status);
            return exit_status; // Return the extracted exit status
        } else {
            fprintf(stderr, "Command did not terminate normally\n");
            return 1; // Error code for abnormal termination
        }
    }
}


#include <iostream>
#include <string>
#include <fstream>

/* Function prototype */
void get_path(std::string &path, std::string &path_deleted);
bool check_txt(std::string path);
void copy_txt(std::string &line, std::fstream &file);

int main()
{
	/* Get file path, create the comment deleted file path */
	std::string path, path_deleted;
	get_path(path, path_deleted);

	/* Define container and file stream object */
	std::string line; //hold content read from the original file
	std::string line_deleted; //hold content to be written to the comment_deleted file
	std::fstream file(path, std::ios::in); //open original file
	std::fstream file_deleted(path_deleted, std::ios::out); //create the deleted file
	/* Copy the content of original file to line */
	copy_txt(line, file);

	/* Start analyzing the string */
	int counter = 0;
	for (int i = 0; i<line.size(); i++)
	{
		//std::cout << line_deleted << "\n";
		//deal with string, everything in "" will be stored, including all comment symbol
		if (line[i] == '"') //entering string section, this if section will transfer all content of the string
		{
			line_deleted.append(1, line[i]); //append the '"' symbol to line_deleted
			i++; //move to next character

			while (line[i] != '"' || (line[i - 1] == '\\' && line[i - 2] != '\\')) //under this condition, the position is still in string, the second expression is for cases like: "asdsaw\"asds\"asd"
			{
				line_deleted.append(1, line[i]); //add to line_deleted
				i++; //move to next character
			}
			line_deleted.append(1, line[i]); //when exiting the above loop, line[i] is the terminating '"'
			continue; //string entering complete, begin next iteration
		}
		//deal with character, everything in '' will be stored, including all comment symbol
		if (line[i] == '\'') //entering character section, this if section will transfer all content of the character to line_deleted
		{
			line_deleted.append(1, line[i]); //append the '\'' symbol to line_deleted
			i++; //move to next character

			while (line[i] != '\'' || (line[i - 1] == '\\' && line[i - 2] != '\\')) //under this condition, the position is still in character, the second expression is for cases like: '\''
			{
				line_deleted.append(1, line[i]); //add to line_deleted
				i++; //move to next character
			}
			line_deleted.append(1, line[i]); //when exiting the above loop, line[i] is the terminating '\''
			continue; //string entering complete, begin next iteration
		}
		//block comment case, begin with /*, terminate with */, skip all content between /* and */
		if (line[i] == '/' && line[i + 1] == '*')
		{
			while (!(line[i] == '*' && line[i + 1] == '/')) //while the end of the comment is not met, proceed
				i++;
			i += 2; //after the above loop, line[i] == '*', should skip two additional character so line[i] is the first character after the block comment
			continue; //skip block comment complete, begin next iteration
		}
		//line comment case, begin with //, terminate with '\n', skip all content between // and '\n', but keep '\n'
		if (line[i] == '/' && line[i + 1] == '/')
		{
			while (line[i] != '\n') //while the end of the line is not met, proceed
				i++;
			line_deleted.append(1, line[i]); //append the '\n' to line_deleted
			continue; //skip line comment complete, begin next iteration 
		}
		//normal character, save to line_deleted, then begin next iteration
		line_deleted.append(1, line[i]);
	}

	/* Write content in line_deleted into the new file */
	file_deleted << line_deleted << "\n";
	file_deleted.close();
	file.close();
	std::cout << "Process completed, please check file: " << path_deleted << "\n";
	return 0;
}

void get_path(std::string &path, std::string &path_deleted)
{
	/* Get file path */
	std::cout << "This program will delete the comments (// or /**/) in a code stored in a txt file.\n"
		<< "Please input the file path you want to process, do not include characters other than English: ";
	getline(std::cin, path);

	/* Define a file stream pbject to check the existence of the file */
	std::fstream test;
	test.open(path, std::ios::in);
	while (test.fail() || !check_txt(path))
	{
		std::cout << "File open failed, please check your file path and reinput: ";
		getline(std::cin, path);
		test.close();
		test.open(path, std::ios::in);
	}

	test.close();

	/* Assign content in path to path_deleted, add "comment_deleted" at the end of the name */
	path_deleted = path;
	path_deleted.erase(path.size() - 4, 4);
	path_deleted += "_comment_deleted.txt";

}

//check the file is txt or not 
bool check_txt(std::string path)
{
	int size = path.size();

	if (path[size - 1] == 't' && path[size - 2] == 'x' && path[size - 3] == 't' && path[size - 4] == '.')
		return 1;
	else
		return 0;
}

//copy the content of original file to a string varible
void copy_txt(std::string &line, std::fstream &file)
{
	std::string transfer;

	while (getline(file, transfer))
	{
		line.append(transfer); //append a line to the end of the string
		line.append(1, '\n'); //append a line terminator to the string, '\n'
	}
}

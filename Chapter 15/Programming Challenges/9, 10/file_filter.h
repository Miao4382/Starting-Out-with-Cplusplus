// this is an abstract class
// the engine of the filter (character transform rule) must be overridden for every derived file filter
#ifndef FILE_FILTER_H
#define FILE_FILTER_H
#include <string>
#include <fstream>

class FileFilter
{
protected:
  std::string input_file_path_; // hold the path for original file 
  std::string output_file_path_; // hold the path for output file (filtered file)
  std::ifstream in; // input file stream object, this object reads content from the original file 
  std::ofstream out; // output file stream object, this object writes content to the output file
  
  /* Function */
  // filter 
  // this function defines the rules of how the character in the original file be altered by the file filter
  // this is a pure virtual function, to be overridden by the derived class of FileFilter
  // no definition of pure virtual function in .cpp file of FileFilter class 
  virtual char Transform(char ch) = 0;
  
  // input path checker
  // this function accepts a string
  // open the file indicated by the string in input mode, check if the path is valid
  // return true if it is valid, close file before exit 
  // return false if it is invalid
  bool CheckInput(std::string i_p);
  
  // output path checker
  // this function accepts a string
  // open the file indicated by the string in output mode, check if the path is valid
  // return true if it is valid, close file before exit 
  // return false if it is invalid
  bool CheckOutput(std::string o_p);  
  
public:
  /* Constructor */
  // default constructor, both path will be assigned with N/A string
  FileFilter()
  {
    input_file_path_ = "N/A";
    output_file_path_ = "N/A";
  }
  
  /* Mutator */
  // set input file path
  // prompt user to input a file path
  // call CheckInput() to examine if the path is valid or not 
  // if it is valid, assign i_p to input_file_path_ (disconnect the file stream object)
  // if it's not, notify user, don't change input_file_path_
  void set_input_file_path();
  
  // set output file path 
  // prompt user to input a file path
  // call CheckOutput() to examine if the path is valid or not 
  // if it is valid, assign o_p to output_file_path_ (disconnect the file stream object)
  // if it's not, notify user, don't change output_file_path_
  void set_output_file_path();
  
  /* Accessor */
  std::string input_file_path() const 
  { return input_file_path_; }
  std::string output_file_path() const
  { return output_file_path_; }
  
  /* Function */
  // begin the actual filter process
  // call CheckInput() and CheckOutput() to see if the file path is valid
  // if not valid, notify user to re-set file path
  // if valid, open the two files 
  // read from the input file from beginning to end, call Transform() to do the actual filter task
  // after finished, notify user that the filter process has finished
  void DoFilter();
  
  
};


#endif
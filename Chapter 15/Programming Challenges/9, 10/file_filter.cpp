#include "file_filter.h"
#include <iostream>

// input path checker
// this function accepts a string
// open the file indicated by the string in input mode, check if the path is valid
// return true if it is valid, close file before exit 
// return false if it is invalid
bool FileFilter::CheckInput(std::string i_p)
{
  in.open(i_p);
  
  if (in.fail())
  {
    in.close();
    return false;
  }

  else
  {
    in.close();
    return true;
  }
    
}

// output path checker
// this function accepts a string
// open the file indicated by the string in output mode, check if the path is valid
// return true if it is valid, close file before exit 
// return false if it is invalid
bool FileFilter::CheckOutput(std::string o_p)
{
  out.open(o_p);
  
  if (out.fail())
  {
    out.close();
    return false;
  }
  
  else 
  {
    out.close();
    return true;
  }
}


/* Mutator */
// set input file path
// prompt user to input a file path
// call CheckInput() to examine if the path is valid or not 
// if it is valid, assign i_p to input_file_path_ (disconnect the file stream object)
// if it's not, notify user, don't change input_file_path_
void FileFilter::set_input_file_path()
{
  std::string i_p;
  std::cout << "Please input the path of the original file: ";
  getline(std::cin, i_p);
  
  if (CheckInput(i_p))
  {
    input_file_path_ = i_p;
  }
  
  else 
  {
    std::cout << "The path for the original file is invalid, please check your path and re-input.\n";
  }
}

// set output file path 
// prompt user to input a file path
// call CheckOutput() to examine if the path is valid or not 
// if it is valid, assign o_p to output_file_path_ (disconnect the file stream object)
// if it's not, notify user, don't change output_file_path_
void FileFilter::set_output_file_path()
{
  std::string o_p;
  std::cout << "Please input the path of the output file: ";
  getline(std::cin, o_p);
  
  if (CheckOutput(o_p))
  {
    output_file_path_ = o_p;
  }
  
  else 
  {
    std::cout << "The path for the output file is invalid, please check your path and re-input.\n";
  }  
}

/* Function */
// begin the actual filter process
// call CheckInput() and CheckOutput() to see if the file path is valid
// if not valid, notify user to re-set file path
// if valid, open the two files 
// read from the input file from beginning to end, call Transform() to do the actual filter task
// after finished, notify user that the filter process has finished
void FileFilter::DoFilter()
{
  if (!(CheckInput(input_file_path_) && CheckOutput(output_file_path_)))
  {
    std::cout << "Invalid file path, please check your file path and reset.\n";
    std::cout << "File convert unsuccessful.\n";
    return;
  }
  
  char ch;
  in.open(input_file_path_);
  out.open(output_file_path_);
  
  while (in.get(ch))
    out << Transform(ch);
  
  std::cout << "File convert completed. Please check the file at " << output_file_path_ << "\n";
  
  in.close();
  out.close();
}
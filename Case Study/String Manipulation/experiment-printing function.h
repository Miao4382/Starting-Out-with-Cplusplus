#include <iostream>

int main()
{
	char letter[67] = "aa aaas ssdw as asdw dff wwewq wewqwe\nssw wwqwe asge sdaw wwe asdw";
	int start_position = 0, line_counter = 0;
	while (letter[start_position + line_counter] != '\0')
	{
		if (line_counter == 0)
		{
			std::cout << "          "; //new line, left margin
			if (letter[start_position] == ' ')
				line_counter++; //If the first element is space, skip that
		}

		if (line_counter > 10 && letter[start_position + line_counter] == ' ')
		{
			std::cout << "          \n"; //end of a line, right margin
			start_position += line_counter;
			line_counter = 0;
			continue;
		}
		else if (letter[start_position + line_counter] == '\n')
		{
			std::cout << "          " << letter[start_position + line_counter]; //end of a line, right margin
			start_position += line_counter+1; //the plus one is to bypass the '\n' character, otherwise this is an infinite loop (always stuck in '\n'
			line_counter = 0;
			continue;
		}
		else
		{
			std::cout << letter[start_position + line_counter];
			line_counter++;
		}
	}

	std::cout << "\n";

	return 0;
}
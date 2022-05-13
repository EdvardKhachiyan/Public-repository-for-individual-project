#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#define SIZE 500

char* base_64_encoder(char input_string[], int string_length)
{
	//we define our 64character set here
	char character_set[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
	char *resulting_string = (char *) malloc(SIZE * sizeof(char));
	int index, number_of_bits = 0, add_zeros = 0, value = 0, count = 0, temporary;
	int i, j;
	int k = 0;
	//here the function should take three bits at a time
	for (i = 0; i < string_length; i = i + 3)
	{
		value = 0, count = 0, number_of_bits = 0;
		for (j = i; j < string_length && j <= i + 2; j++)
		{
			//here the value shifts by8 to open up space for one additional character
			value = value << 8;
			//to store the characters in value
			value = value | input_string[j];
			//count so to say shows how many characters we got after this
			count++;
		}
		//as each character is8 bits
		number_of_bits = count * 8;
		//this gets how many spaces it should later fill with zeros
		add_zeros = number_of_bits % 3;
		while (number_of_bits != 0)
		{
			//we are checking with six as we had to take six bits at a time in order to get our encoded values
			//it stops when the number of bits gets less than six, then else works
			if (number_of_bits >= 6)
			{
				temporary = number_of_bits - 6;
				//to cut out the so to say extra part
				index = (value >> temporary) & 63;
				number_of_bits = number_of_bits - 6;		
			}
			else
			{
				temporary = 6 - number_of_bits;
				//and gives index its new value by adding extra space at the right side which will be filled with 0s
				index = (value << temporary) & 63;
				//its job is basically done
				number_of_bits = 0;
			}
			//it gets the corresponding characters from our initial 64set and assigns them to the resulting string
			resulting_string[k++] = character_set[index];
		}
	}
			//this fucntion here adds zeros
			for (i = 1; i <= add_zeros; i++)
			{
			//puts = wherever there is a zero at the end, as defined in previous functions	
			resulting_string[k++] = '=';
			}
			//closes the string with the 'last element'
			resulting_string[k] = '\0';
			//returns our resulting string
			return resulting_string;
}



int main()
{
	int string_length;
	char input_string [SIZE];
        printf("Please enter your text:\n");
	//this helps to take all the characters as one, merged string
	scanf ("%[^\n]%*c", input_string);
	//gives the length of the input string to the 'length' which is the length of the copy array
	int length = strlen(input_string);
	//cpy creation helps to keep the input size known, we will work with the copuied input in the function too
        char input_copy [length];
	//assigns each element from original input string to the copy input
	for(int i =0; i < strlen(input_string); i++){
		input_copy[i] = input_string[i];
	} 
	//removing this part helps to avoid any rubbish
	string_length = sizeof(input_copy) / sizeof(input_copy[0]); 
	printf("Your input string is: %s\n", input_copy);
	//runs the input copy through our encoding function and prints it
	printf("Your Base 64 encoded string is: %s\n", base_64_encoder(input_copy, string_length));
	return 0;
}



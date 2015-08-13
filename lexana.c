 /*					Scanner for C-language 

 						Part 1

The program implemets a scanner for C-language. The code is written in C language. The input to the program, is a C code and the programs scans the complete code. The scanner(program) recognise the tokens and categorize them, this is known as tokenization. The programs output the tokens with their category such as identifier, keywords, opearator, integer constant, real constant, strings. The scanner also prints the error such as invalid tokens with the line numbers. 

The scanner is basically a implementation of the following DFA. 



//---------------------------------DFA----------------------------------------//



The code implements the above DFA using simple switch statement. Depending on the present state and the current character read, transition takes place. 

Character Set of the DFA

Alphabets :         A, B , C , D , E , ......X, Y, Z
	              a , b , c , d, e, ...........x , y, z

Digit:                   0,1,2,3,4,5,6,7,8,9

Special Symbols: ! # %  & * ( )_ + - = ^
	
 There are 19 states, 
 
Initial States:	q0

Final States:
 		q1        (Identifier or keyword)
 		q2        (Integer Constant)
 		q4        (Real Constant)
 		q6        (String Constant)
		q8        (Preprocessor Statement)
		q9        (Braces)
 		q10      (Delimeter)
 		q13      (Single line comments)
 		q16      (Multiple line comment
  		q17      (Operators(+ , - ,  %  , = , ^ )
 		q18      (Operators(>,<,!)
		q19       (>= , <= , != )

Intermediate States

 q3, q7, q11, q12, q14,  q15


 Tokens recognized by the scanner
1) Identifier or keyword
2)  Integer Constant
3)   Real Constant
4)   String Constant
5)    Preprocessor Statement
6)    Braces
7)    Delimeter
8)    Single line comments
9)     Multiple line comment
10)     Operators + , - ,  %  , = , ^ , > , < , ! , >= , <= , != 

Assumptions

The scanner doesnot differentiate between the kinds of operator and simply tag all operators with a same token 'operator'. Its leaves this work for the parser to differentiate between different kinds of operator. 
There is no support for the ternary operator.
String constants including “ escaped by by / are also not supported, rather /” is recognized as two different characters.

*/

//---------------------------------Code Begins--------------------------------//
#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
#include<fcntl.h>

void lex(int fd);

void main(int argc, char* argv[])
{
	int fd;
	fd=open("a.c",O_RDONLY); //open source file
	
	lex(fd); 
}

void lex(int fd)
{
	char buffer[1000],temp; //buffer to store the tokens 
	int i=0,state=0, category,flag=0,j=0; //state variable keeps the present state
	int line_no=1,errors=0; //for keeping track of present line number and errors for counting the no of errors
	char keywords[][20]= {
				"auto",
				"break",
				"case",
				"const",
				"continue",
				"default",
				"do",
				"else",
				"extern",
				"for",
				"goto",
				"if",
				"long",
				"register",
				"return",
				"short",
				"signed",
				"sizeof",
				"static",
				"struct",
				"switch",
				"typedef",
				"union",
				"unsigned",
				"volatile",
				"while"	}; 
	
	if(fd==-1) //error opening file
	{
		printf("File Not found");
	}
	
	else
	{
		
		
		while(read(fd,&temp,1)!=0) //read the file character by character
		{								//Python33\Lib\site-packages\pip\vendor\html5lib\filters\samples.py
			
			if(temp=='\n')
				line_no++;
					
			
			start: //label to resume the loop when a token can not be recognized by a particular state
			
			
			switch(state)
			{
			
				case 0: //initial state
					i=0;
					buffer[i++]=temp;
					
					if(isalpha(temp))
						state=1;
					
					else if(isdigit(temp))
						state=2;
					else if(temp=='.')
					{
						state=3;
					}	
					else if(temp=='\n' || temp=='\t' || temp==' ')
					{	
						state=0;
						i=0;	
					}
					else if(temp=='\"')
					{
						state=5;
						i=0;
									
					}
					else if(temp=='#')
					{
						state=7;
						
									
					}
					else if(temp=='(' || temp==')' || temp=='{' || temp=='}' || temp=='[' || temp==']' )
					{
						state=9;
															
					}
					else if(temp==':' || temp==';' || temp==',')
					{
						state=10;
															
					}
					else if(temp=='/')
					{
						state=11;
						
					}
					else if(temp=='+' || temp=='-' || temp=='%' || temp=='!' || temp=='=' || temp=='^' )
					{
						state=17;
					}
					else if(temp=='<' || temp=='>' || temp=='!')
					{
						state=18;
					}
					else
					{
						state=-1;
						goto start;
					}
					break;
					
					
				
				case 1: //identifier final state
					if(isalpha(temp) || isdigit(temp) || temp=='_')
						buffer[i++]=temp;
					else
					{
						
						buffer[i]='\0';
						//check whether it is a keyword or not
						for(j=0;j<26;j++)
						{
							if(strcmp(keywords[j],buffer)==0)
								flag=1;
						}		
						if(flag==0)
							printf("\n%s:Identifier",buffer);	
						else
							printf("\n%s:Keyword",buffer);
							
					//	sleep(1);
						i=0;
						state=0;
						flag=0;
						goto start;
					}
					break;
					
					
					
				case 2:
					if(isdigit(temp))
						buffer[i++]=temp;
					
					else if(temp=='.')
					{
						buffer[i++]=temp;
						state=3;
					
					}
					else
					{
						
						buffer[i]='\0';
						printf("\n%s:Integer Constant",buffer);	
						i=0;
						state=0;
						goto start;			
					}
				
					break;
					
					
					
					
				case 3:
					
					if(isdigit(temp))
					{
						buffer[i++]=temp;
						state=4;
					}
					else
					{
						buffer[i]='\0';
						printf("\n%sError, expecting a digit, Line number:%d, State:%d ",buffer,line_no,state);
						errors++;
						state=0;
						i=0;
					}	
					break;	
				case 4:
					if(isdigit(temp))
					{
						buffer[i++]=temp;
						state=4;
					}
					else
					{
						
						buffer[i]='\0';
						printf("\n%s:Real Constant",buffer);	
						i=0;
						state=0;
						goto start;			
					}
					break;
				case 5:
					if(temp!='\"')
					{
						buffer[i++]=temp;
						state=5;
					
					}		
					else
					{	
						state=6;
						buffer[i]='\0';
						printf("\n%s:String Constant",buffer);
						i=0;
						state=0;
					
					}	      
				       	break;
				
				
				case 6:
					break;
					
				case 7:
					
					if(temp!='\n')
					{
						buffer[i++]=temp;
						state=7;
					
					}		
					else
					{	
						state=8;
						buffer[i]='\0';
						printf("\n%s:Preprocessor Statement",buffer);
						i=0;
						state=0;
					
					}	      
				       	break;
				case 8:	
					
					break;
					
				case 9:
					buffer[i]='\0';
					printf("\n%s:Braces",buffer);
					i=0;
					state=0;
					goto start;
					break;	
				
				case 10:
					buffer[i]='\0';
					printf("\n%s:Delimeter",buffer);
					i=0;
					state=0;
					goto start;
					break;	
					
					
				case 11:
					if(temp=='/')
					{
						state=12;
						i=0;
					
					}
					else if(temp=='*')
					{
						state=14;
						i=0;
					}
					else
					{
						buffer[i]='\0';
						printf("\n%s:Division Operator",buffer);
						state=0;
						i=0;
					}
					break;
					
				case 12:
				
					if(temp!='\n')
					{
						buffer[i++]=temp;
						state=12;
					
					}		
					else
					{	
						state=13;
						buffer[i]='\0';
						printf("\n%s:Single Line comment",buffer);
						i=0;
						state=0;
					
					}	      
				       	break;
				case 13:
					break;
				case 14:
					if(temp!='*')
					{
						buffer[i++]=temp;
						state=14;
					
					}		
					else
					{	
						state=15;
						buffer[i++]=temp;
						
					
					}	      
				       	break;	
				case 15:
				
					if(temp!='/')
					{
						buffer[i++]=temp;
						state=14;
					
					}		
					else
					{	
						state=16;
						buffer[--i]='\0';
						printf("\n%s:Multiple Line Comment",buffer);
						i=0;
						state=0;
					
					}	      
				       	break;
				case 16:
				
					break;		
					
				case 17:
					buffer[i]='\0';
					printf("\n%s:Operator",buffer);
					state=0;
					i=0;
					break;
				
				case 18:
					if(temp=='=')
					{
						state=19;
						buffer[i]='\0';
						printf("\n%s:Relational Operator",buffer);
						state=0;
						i=0;
						
					}
					else
					{
						buffer[i]='\0';
						printf("\n%s:Relational Operator",buffer);
						state=0;
						i=0;
						goto start;
					}
						
				default: //if a character can not be accepted by initial state
					buffer[i]='\0';
					errors++;
					printf("\n%s: Unidentified token, Line number:%d, State:%d ",buffer,line_no,state);
					i=0;
					state=0;
			}
		
		
		}
		
	
	}
	
	close(fd); //close the source file
 
}		

// Evaluation of prefix notation

float evaluateUtil(char str[],stack<char> S)
{
	

	while(S.empty()==false)
	{
		char a = pop(S);
		if(a>='0' && a<='9')
		{
			int res = a - '0';
			return res;
		}

		float b= evaluate(S);
		float c= evaluate(S);
		if(a=='+')
		{
			return a+b;
		}
		if(a=='-')
		{
			return a-b;
		}
		if(a=='*')
		{
			return a*b;
		}
		if(a=='÷')
		{
			return a/b;
		}
	}
}

float eval(char str[])
{
	int n= str.size();
	stack<char> S;
	
	for(int i=str.size()-1;i>=0;i--)
	{
            S.push(str[i]);
	}

	float c= evaluateUtil(str,S);
	return c;
}

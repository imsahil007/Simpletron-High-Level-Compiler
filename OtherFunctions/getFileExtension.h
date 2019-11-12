int getFileExtension(char *str, int whichfile)
{
	//whichfile = 0 for input 1 for output
	char s[4];
	int  j = 0, i = strlen(str)-3;
	
	while( j!=3 )
		s[j++] = str[i++];
	s[j] = '\0';
	if((((!strcmp(s,"shl"))|| (!strcmp(s,"SHL")))&& whichfile == 0)||
	(((!strcmp(s,"sml"))|| (!strcmp(s,"SML")))&& whichfile == 1))
		return 1;
	else return 0;
}

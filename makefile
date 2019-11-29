all: main.c firstpass.c secondpass.c myAtoi.c getLocation.c
	gcc main.c firstpass.c secondpass.c myAtoi.c shlToSML.c postfix_SML.c infixToPostfix.c getTokens.c fillSymbolTable.c getLocation.c check.c addExpression.c getFlag.c solveReferences.c saveSMLfile.c addbranchloc.c compressSML.c initialize.c getFileExtension.c -o compiler.o
getFileExtension: getFileExtension.c
	gcc -c getFileExtension.c
firstpass: firstpass.c myAtoi.c getLocation.c shlToSML.c postfix_SML.c infixToPostfix.c getTokens.c fillSymbolTable.c check.c addExpression.c initialize.c
	gcc -c firstpass.c myAtoi.c getLocation.c shlToSML.c postfix_SML.c infixToPostfix.c getTokens.c fillSymbolTable.c check.c addExpression.c initialize.c
initialize: initialize.c
	gcc -c initialize.c
addExpression: addExpression.c
	gcc -c addExpression.c
check: check.c
	gcc -c check.c
getTokens: getTokens.c myAtoi.c
	gcc -c getTokens.c myAtoi.c
fillSymbolTable: fillSymbolTable.c myAtoi.c shlToSML.c addExpression.c
	gcc -c fillSymbolTable.c myAtoi.c shlToSML.c addExpression.c
infixToPostfix: infixToPostfix.c
	gcc -c infixToPostfix.c
postfix_SML: postfix_SML.c
	gcc -c postfix_SML.c
shlToSML: shlToSML.c myAtoi.c getLocation.c
	gcc -c shlToSML.c myAtoi.c getLocation.c
secondpass: secondpass.c myAtoi.c getLocation.c getFlag.c solveReferences.c saveSMLfile.c addbranchloc.c compressSML.c
	gcc -c secondpass.c myAtoi.c getLocation.c getFlag.c solveReferences.c saveSMLfile.c addbranchloc.c compressSML.c
compressSML: compressSML.c
	gcc -c compressSML.c
addbranchloc: addbranchloc.c
	gcc -c addbranchloc.c
saveSMLfile: saveSMLfile.c
	gcc -c saveSMLfile.c
solveReferences: solveReferences.c getFlag.c addbranchloc.c
	gcc solveReferences.c getFlag.c addbranchloc.c
myAtoi: myAtoi.c
	gcc -c myAtoi.c
getLocation:getLocation.c
	gcc -c getLocation.c
clear_obj: *.o
	rm *.o
clear_SML: *.sml
	rm *.sml
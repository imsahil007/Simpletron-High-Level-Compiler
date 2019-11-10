#include "firstpass/myAtoi.h"
#include "firstpass/infixToPostfix.h"
#include "firstpass/postfix_SML.h"
#include "firstpass/getTokens.h"
#include "firstpass/check.h"
#include "firstpass/addExpression.h"
#include "secondpass/saveSMLfile.h"
#include "getLocation.h"
#include "firstpass/shlToSML.h"
#include "secondpass/getFlag.h"
#include "firstpass/fillSymbolTable.h"
#include "firstpass/initialize.h"
#include "firstpass/firstPass.h"
#include "secondpass/solveReferences.h"
#include "secondpass/secondPass.h"

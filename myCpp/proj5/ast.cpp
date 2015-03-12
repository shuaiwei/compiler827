// Companion source code for "flex & bison", published by O'Reilly
// helper functions for fb3-1
#  include <iostream>
#  include <fstream>
#  include <stdlib.h>
#  include "ast.h"
#  include <math.h>

double eval(Ast *a) {
  double v = 0;
  switch( a->getNodetype() ) {
  case 'K': v = a->getNumber(); break;
  case '+': v = eval(a->getLeft()) + eval(a->getRight()); break;
  case '-': v = eval(a->getLeft()) - eval(a->getRight()); break;
  case '*': v = eval(a->getLeft()) * eval(a->getRight()); break;
  case '^': v = pow(eval(a->getLeft()), eval(a->getRight())); break;
  case '/': v = eval(a->getLeft()) / eval(a->getRight()); break;
  case 'M': v = -eval(a->getLeft()); break;
  case '1': v = eval(a->getLeft()) < eval(a->getRight()) ? 1 : 0; break;
  case '2': v = eval(a->getLeft()) <= eval(a->getRight()) ? 1 : 0; break;
  case '3': v = eval(a->getLeft()) > eval(a->getRight()) ? 1 : 0; break;
  case '4': v = eval(a->getLeft()) <= eval(a->getRight()) ? 1 : 0; break;
  case '5': v = eval(a->getLeft()) != eval(a->getRight()) ? 1 : 0; break;
  case '6': v = eval(a->getLeft()) == eval(a->getRight()) ? 1 : 0; break;
  case '%': v = eval(a->getLeft()) % eval(a->getRight()); break;


  default: std::cout << "internal error: bad node "
                << a->getNodetype() << std::endl;;
  }
  return v;
}

void treeFree(Ast *a) {
  switch(a->getNodetype()) {
   // two subtrees
  case '+':
  case '-':
  case '*':
  case '/':
  case '^':
    treeFree(a->getRight());

   // one subtrees
  case 'M':
    treeFree(a->getLeft());

   //no subtree
  case 'K':
    delete a;
    break;

  default: std::cout << "internal error: bad node "
                << a->getNodetype() << std::endl;;
  }
}

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

void makeGraph1( Ast* node, std::fstream& output)  {  
  if ( node && node->getNodetype() != 'K') {
    if ( node->getLeft() ) {
      output << "   " << "\"a" << node->getID() << "\"" << "->"; 
      switch( node->getLeft()->getNodetype() ) {
        case 'K':
          output  << "\"a" << node->getLeft()->getID() << "\"" << std::endl; break;
        default:
          output << "\"a" << node->getLeft()->getID() << "\"" << std::endl;
      }
      makeGraph1( node->getLeft(), output );
    }

    if ( node->getRight() ) {
      output << "   " << "\"a" << node->getID() << "\"" << "->";
      switch( node->getRight()->getNodetype() ) {
        case 'K':
          output << "\"a" << node->getRight()->getID() << "\"" <<  std::endl;break;
        default:
          output << "\"a" << node->getRight()->getID() << "\"" << std::endl;
      }
      makeGraph1( node->getRight(), output );
    }
  }
}

void makeGraph2(Ast* node, std::fstream& output){
  if(node->getNodetype() == 'K'){
     output << "   " << "\"a" << node->getID() << "\"" << 
      " [label=" << "\"" << node->getNumber() << "\"" << 
      ",color=green, style=filled]" << std::endl; 
    }
  else{
    if(node->getNodetype() == 'M'){
       output << "   " << "\"a" << node->getID() << "\"" << 
        " [label=\"-\""  << std::endl;
    }
    else if(node->getNodetype() == '^'){
       output << "   " << "\"a" << node->getID() << "\"" << 
        " [label=\"**\""  << std::endl;
    }
    else {
       output << "   " << "\"a" << node->getID() << "\"" << 
        " [label=" << "\"" << node->getNodetype() << "\"" << std::endl;
     
    }
     switch(node->getNodetype()){
      case '+':
        output << ",color=yellow, style=filled ,shape=polygon]" << std::endl; break;
      case '-':
        output << ",color=yellow, style=filled ,shape=polygon]" << std::endl; break;
      case '*':
        output << ",color=blue, style=filled ,shape=invtriangle]" << std::endl; break;
      case '/':
        output << ",color=blue, style=filled ,shape=invtriangle]" << std::endl; break;
      case 'M':
       output << ",color=purple, style=filled ,shape=triangle]" << std::endl; break;
      case '^':
       output << ",color=orange, style=filled ,shape=triangle]" << std::endl; break;
      default: ;

     }
     makeGraph2(node->getLeft(), output);
     if(node->getNodetype() != 'M' ){
      makeGraph2(node->getRight(), output);
    }
  }
}


void makeGraph(Ast* node) {
  std::fstream output;
  output.open("graph.gv", std::ios::out);
  output << "digraph G {" << std::endl;
  makeGraph1(node, output); //creat nodes and edges
  makeGraph2(node,output); //set label
  output << "}" << std::endl;
  output.close();
}

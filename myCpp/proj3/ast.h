//  Declarations for an AST calculator
//  From "flex & bison", fb3-1, by John Levine
//  Adapted by Brian Malloy
#include <iostream>
#include <string>
#include <fstream>
extern void yyerror(const char*);
extern void yyerror(const char*, const char);

class Ast {
public:
  Ast(char nt, int ID) : nodetype(nt), identifier(ID) {}
  virtual ~Ast() {}
  char getNodetype() const { return nodetype; }

  int getID() const { return identifier; }

  virtual Ast* getLeft() const { throw std::string("No Left"); }
  virtual Ast* getRight() const { throw std::string("No Right"); }
  virtual double getNumber() const { throw std::string("No Number"); }
private:
  char nodetype;
  int identifier;
};

class AstNode : public Ast {
public:
  AstNode(char nt, int ID, Ast* l, Ast* r) : 
    Ast(nt,ID), left(l), right(r) 
  {}
  virtual ~AstNode() {}
  virtual Ast* getLeft() const  { return left; }
  virtual Ast* getRight() const { return right; }
  
private:
  Ast *left;
  Ast *right;
};

class AstNumber : public Ast {
public:
  AstNumber(char nt, int ID, double n) : Ast(nt,ID), number(n) {} 
  virtual ~AstNumber() {}
  virtual double getNumber() const { return number; }
private:
  double number;
};

double eval(Ast*);   // Evaluate an AST
void treeFree(Ast*); // delete and free an AST 

void makeGraph1(Ast*, std::fstream&);
void makeGraph2(Ast*, std::fstream&);
void makeGraph(Ast*);


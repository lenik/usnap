#define dti8	char
#define DTI8	unsigned char
#define dti16	int
#define DTI16	unsigned int
#define dti32   long
#define DTI32	unsigned long

#define dtf32	float
#define dtf64	double
#define dtf80	long double

struct _OpIndex{
  char *O;
  _OpIndex *Prev;
  _OpIndex *Next;
  _OpIndex(char *OS);
  ~_OpIndex();
}*OpIndex;
_OpIndex::_OpIndex(char *OS){
  O=new char[strlen(OS+1)];
  strcpy(O, OS);
}
_OpIndex::~_OpIndex(){
  delete O;
}
void InitOpIndex();

class Operator{
public:
  char *O;
  Operator();
  Operator(char *OS);
  ~Operator();
};

Operator::Operator(){
  O=new char;
}
Operator::Operator(char *OS) {
  O=new char[strlen(OS)+1];
  strcpy(O, OS);
}
Operator::~Operator(){
  delete O;
}

class Add:public Operator {
  dti8  Calc(dti8  a1, dti8  a2);
  DTI8  Calc(DTI8  a1, DTI8  a2);
  dti16 Calc(dti16 a1, dti16 a2);
  DTI16 Calc(DTI16 a1, DTI16 a2);
  dti32 Calc(dti32 a1, dti32 a2);
  DTI32 Calc(DTI32 a1, DTI32 a2);
  dtf32 Calc(dtf32 a1, dtf32 a2);
  dtf64 Calc(dtf64 a1, dtf64 a2);
  dtf80 Calc(dtf80 a1, dtf80 a2);
};
class Sub:public Operator {
  dti8  Calc(dti8  a1, dti8  a2);
  DTI8  Calc(DTI8  a1, DTI8  a2);
  dti16 Calc(dti16 a1, dti16 a2);
  DTI16 Calc(DTI16 a1, DTI16 a2);
  dti32 Calc(dti32 a1, dti32 a2);
  DTI32 Calc(DTI32 a1, DTI32 a2);
  dtf32 Calc(dtf32 a1, dtf32 a2);
  dtf64 Calc(dtf64 a1, dtf64 a2);
  dtf80 Calc(dtf80 a1, dtf80 a2);
};
class Mul:public Operator {
  dti8  Calc(dti8  a1, dti8  a2);
  DTI8  Calc(DTI8  a1, DTI8  a2);
  dti16 Calc(dti16 a1, dti16 a2);
  DTI16 Calc(DTI16 a1, DTI16 a2);
  dti32 Calc(dti32 a1, dti32 a2);
  DTI32 Calc(DTI32 a1, DTI32 a2);
  dtf32 Calc(dtf32 a1, dtf32 a2);
  dtf64 Calc(dtf64 a1, dtf64 a2);
  dtf80 Calc(dtf80 a1, dtf80 a2);
};
class Div:public Operator {
  dti8  Calc(dti8  a1, dti8  a2);
  DTI8  Calc(DTI8  a1, DTI8  a2);
  dti16 Calc(dti16 a1, dti16 a2);
  DTI16 Calc(DTI16 a1, DTI16 a2);
  dti32 Calc(dti32 a1, dti32 a2);
  DTI32 Calc(DTI32 a1, DTI32 a2);
  dtf32 Calc(dtf32 a1, dtf32 a2);
  dtf64 Calc(dtf64 a1, dtf64 a2);
  dtf80 Calc(dtf80 a1, dtf80 a2);
};

dti8  Add::Calc(dti8  a1, dti8  a2) {return a1+a2;}
DTI8  Add::Calc(DTI8  a1, DTI8  a2) {return a1+a2;}
dti16 Add::Calc(dti16 a1, dti16 a2) {return a1+a2;}
DTI16 Add::Calc(DTI16 a1, DTI16 a2) {return a1+a2;}
dti32 Add::Calc(dti32 a1, dti32 a2) {return a1+a2;}
DTI32 Add::Calc(DTI32 a1, DTI32 a2) {return a1+a2;}
dtf32 Add::Calc(dtf32 a1, dtf32 a2) {return a1+a2;}
dtf64 Add::Calc(dtf64 a1, dtf64 a2) {return a1+a2;}
dtf80 Add::Calc(dtf80 a1, dtf80 a2) {return a1+a2;}
dti8  Sub::Calc(dti8  a1, dti8  a2) {return a1+a2;}
DTI8  Sub::Calc(DTI8  a1, DTI8  a2) {return a1+a2;}
dti16 Sub::Calc(dti16 a1, dti16 a2) {return a1-a2;}
DTI16 Sub::Calc(DTI16 a1, DTI16 a2) {return a1-a2;}
dti32 Sub::Calc(dti32 a1, dti32 a2) {return a1-a2;}
DTI32 Sub::Calc(DTI32 a1, DTI32 a2) {return a1-a2;}
dtf32 Sub::Calc(dtf32 a1, dtf32 a2) {return a1-a2;}
dtf64 Sub::Calc(dtf64 a1, dtf64 a2) {return a1-a2;}
dtf80 Sub::Calc(dtf80 a1, dtf80 a2) {return a1-a2;}
dti8  Mul::Calc(dti8  a1, dti8  a2) {return a1*a2;}
DTI8  Mul::Calc(DTI8  a1, DTI8  a2) {return a1*a2;}
dti16 Mul::Calc(dti16 a1, dti16 a2) {return a1*a2;}
DTI16 Mul::Calc(DTI16 a1, DTI16 a2) {return a1*a2;}
dti32 Mul::Calc(dti32 a1, dti32 a2) {return a1*a2;}
DTI32 Mul::Calc(DTI32 a1, DTI32 a2) {return a1*a2;}
dtf32 Mul::Calc(dtf32 a1, dtf32 a2) {return a1*a2;}
dtf64 Mul::Calc(dtf64 a1, dtf64 a2) {return a1*a2;}
dtf80 Mul::Calc(dtf80 a1, dtf80 a2) {return a1*a2;}
dti8  Div::Calc(dti8  a1, dti8  a2) {return a1/a2;}
DTI8  Div::Calc(DTI8  a1, DTI8  a2) {return a1/a2;}
dti16 Div::Calc(dti16 a1, dti16 a2) {return a1/a2;}
DTI16 Div::Calc(DTI16 a1, DTI16 a2) {return a1/a2;}
dti32 Div::Calc(dti32 a1, dti32 a2) {return a1/a2;}
DTI32 Div::Calc(DTI32 a1, DTI32 a2) {return a1/a2;}
dtf32 Div::Calc(dtf32 a1, dtf32 a2) {return a1/a2;}
dtf64 Div::Calc(dtf64 a1, dtf64 a2) {return a1/a2;}
dtf80 Div::Calc(dtf80 a1, dtf80 a2) {return a1/a2;}

void InitOpIndex(void){
  _OpIndex *Last;
  OpIndex=new _OpIndex("+");
  OpIndex->Prev=NULL;
  Last=OpIndex;
  OpIndex=new _OpIndex("-");
}

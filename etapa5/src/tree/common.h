#ifndef COMMON_H
#define COMMON_H

#include <string>
#include <tr1/unordered_map>

class Symbol;

namespace Common {

typedef enum TokenType {
  LIT_INT,
  LIT_FLOAT,
  LIT_BOOL,
  LIT_CHAR,
  LIT_STRING,
  IDENTIFIER,
  VARIABLE,
  VECTOR_VAR,
  FUNCTION,
  PARAMETER
} TokenType;

typedef enum DataType {
  BOOL,
  INT,
  FLOAT,
  CHAR,
  STRING,
  VECTOR
} DataType;

typedef enum OperationType {
    OP_SUM,
    OP_SUB,
    OP_MULT,
    OP_DIV,
    OP_LESS,
    OP_GREATER,
    OP_LE,
    OP_GE,
    OP_EQUAL,
    OP_NEQUAL,
    OP_AND,
    OP_OR,
    OP_PAREN
} OperationType;

typedef enum ILOC_OperationType {
    ILOC_NOP,
    ILOC_ADD,
    ILOC_SUB,
    ILOC_MULT,
    ILOC_DIV,
    ILOC_ADDI,
    ILOC_SUBI,
    ILOC_RSUBI,
    ILOC_MULTI,
    ILOC_DIVI,
    ILOC_RDIVI,
    ILOC_LSHIFT,
    ILOC_LSHIFTI,
    ILOC_RSHIFT,
    ILOC_RSHIFTI,
    ILOC_AND,
    ILOC_ANDI,
    ILOC_OR,
    ILOC_ORI,
    ILOC_XOR,
    ILOC_XORI,
    ILOC_LOADI,
    ILOC_LOAD,
    ILOC_LOADAI,
    ILOC_LOADA0,
    ILOC_CLOAD,
    ILOC_CLOADAI,
    ILOC_CLOADA0,
    ILOC_STORE,
    ILOC_STOREAI,
    ILOC_STOREA,
    ILOC_CSTORE,
    ILOC_CSTOREAI,
    ILOC_CSTOREA0,
    ILOC_I2I,
    ILOC_C2C,
    ILOC_C2I,
    ILOC_I2C,
    ILOC_JUMPI,
    ILOC_JUMP,
    ILOC_CBR,
    ILOC_CMP_LT,
    ILOC_CMP_LE,
    ILOC_CMP_EQ,
    ILOC_CMP_GE,
    ILOC_CMP_GT,
    ILOC_CMP_NE
} ILOC_OperationType;

typedef std::tr1::unordered_map<std::string, Symbol*> HashTable;

}

#endif // COMMON_H

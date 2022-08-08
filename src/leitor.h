#ifndef LEITOR_H
#define LEITOR_H

#include <stdio.h>
#include <stdlib.h>
#include "estruturas.h"
#include "classFile.h"
#include "instructions.h"

/* Assinatura dos métodos */
u1 u1Read(FILE *fp);                                                                // Lê um byte do arquivo e retorna o u1 
u2 u2Read(FILE *fp);                                                                // Lê dois byte
u4 u4Read(FILE *fp);                                                                // Lê quatro bytes

/* Funções Auxiliares */
ClassFile * readFile(char *);                                                       // Função que vai ler o arquivo .class
cp_info * readConstantPool(FILE * fp, u2 constantpoolcount);                        // Lê a constant pool do .class
method_info * readMethod(FILE * fp, u2 methodscount, cp_info *cp);                  // Lê o método de uma classe
char* decodeInstructionOp(cp_info *cp, u2 index, u2 sizeCP);                        // Decodifica os argumentos de uma instrução
char* decodeCode(cp_info *cp,u2 sizeCP,u1 *code, u4 length,instruction *instrucoes);  // Decodifica o código do método
field_info * readField(FILE * fp, u2 fields_count, cp_info * cp);
u2 * readInterfaces(FILE * fp, u2 size);
innerClasses_attribute * readInnerClasses(FILE * fp, cp_info * cp);
exceptions_attribute * readExceptionsAttribute(FILE * fp);
classes * readClasses(FILE * fp);
constantValue_attribute * readConstantValue(FILE * fp);
double decodeDoubleInfo(cp_info * cp);
uint64_t decodeLongInfo(cp_info * cp);
float decodeFloatInfo(cp_info * cp);
int decodeIntegerInfo(cp_info * cp);
signature_attribute * readSignature(FILE * fp);                                     // Lê as flags recebidas (do acesso)
char* organizingFlags(char* flagsOrdemInversa);                                     // Organiza as flags
stackMapTable_attribute * readStackMapTable(FILE * fp);                             // Lê o stack table
stack_map_frame * readStackMapFrame(FILE * fp);
int setOffsetPrinting(int posicao, u1 offset);                                      // Organiza o offset do stack frame
verification_type_info * readVerificationTypeInfo(FILE * fp);
code_attribute * readCode(FILE * fp, cp_info *cp);
line_number_table * readLineNumberTable(FILE * fp, cp_info *cp);
exception_table * readExceptionTable (FILE * fp, u2 size);
attribute_info * readAttributes (FILE * fp, cp_info *cp);
source_file_attribute * readSourceFile (FILE * fp);
char* searchNameTag(u1 tag);
char* decodeStringUTF8(cp_info *cp);
char* decodeNIeNT(cp_info *cp, u2 index,u1 tipo);
char* decodeAccessFlags(u2 flag);
void printClassFile(ClassFile *, FILE *);                                           // Imprime o arquivo .class

#endif

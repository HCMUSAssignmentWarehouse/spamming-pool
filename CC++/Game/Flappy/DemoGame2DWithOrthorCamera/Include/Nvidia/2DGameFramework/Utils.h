#pragma once
#include <stdio.h>
#include "Texture.h"
#include "Shader.h"
#include "Entity2D.h"
#include "State.h"
#define MAX_VAL 100000
#define MIN_VAL -100000
#define RANDOMSEEDX 21231215
#define RANDOMSEEDY 79841325
#define RANDOMSEEDZ 32496511

struct MatchStringTexture
{
 MatchStringTexture(const std::string& s) : s_(s) {}
 bool operator()(Texture* obj) 
 {
	 string tam=obj->GetPath();
	 string s=s_;
	 return obj->GetPath() == s_;

 }
 private:
   const std::string& s_;
};

struct MatchStringShader
{
 MatchStringShader(const std::string& s) : s_(s) {}
 bool operator()(Shaders* obj) 
 {
	 string tam=obj->GetVertexShaderPath();
	 string s=s_;
	 return tam==s;
 }
 private:
   const std::string& s_;
};


struct MatchStringState
{
 MatchStringState(const std::string& s) : s_(s) {}
 bool operator()(State* obj) 
 {
	 return obj->GetName() == s_;
 }
 private:
   const std::string& s_;
};

void ReadLine(FILE *pFile, char* buffer);

bool ReadToKey(FILE* pf, char key);

int SeekToNumber(char* buffer, int iStart);

int ScanNumberInt32(char* buffer, int *iNumber, int iStart);

int ScanNumberUInt32(char* buffer, unsigned int *iNumber, int iStart);

int ScanNumberFloat32(char* buffer, float *iNumber, int iStart);

int SeekToQuote(char* buffer, int iStart);

int ScanPath(char* buffer, char* Path, int iStart);

bool IsInCameraView(Entity2D*);

unsigned int  GetARandomNumber();

Matrix InvertMatrix(Matrix);

double Det(Matrix m,int n);

double Distance(Vector3 pos1, Vector3 pos2);

void Log(const char*s);
float Abs(float value);

float Roundf(float value);

int ArrCharLen(char*);

Vector3 ConvertCoordinate2D3D(BaseCamera* cam,Vector2 pos2D);

Vector2 ConvertCoordinate3D2D(BaseCamera* cam,Vector3 pos3D);

float MaxF(float v1,float v2);
float MinF(float v1,float v2);
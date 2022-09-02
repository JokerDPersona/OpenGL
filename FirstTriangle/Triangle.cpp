//
// Created by 李圳熊 on 2022/9/2.
//

#include <GLTools.h>
#include <GLShaderManager.h>

#ifdef _APPLE_
#include <glut/glut.h> //OS X
#else
#define FREEGLUT_STATIC
#include <GL/glut.h> //windows
#endif

GLBatch triangleBatch;
GLShaderManager shaderManager;

void ChangeSize(int w,int h){

}

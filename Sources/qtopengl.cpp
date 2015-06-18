#include "qtopengl.h"

#include "Screen.h"
#include "Mob.h"

#include <QMouseEvent>
#include <QKeyEvent>

QtOpenGL::QtOpenGL(QWidget *parent) : QGLWidget(parent)
{
    SetGLContext(this);
}

QtOpenGL::~QtOpenGL()
{

}


void QtOpenGL::mousePressEvent(QMouseEvent* event)
{
    if ((event->button() == Qt::LeftButton) && GetManager())
    {
        GetManager()->ProcessClick(event->x(), event->y());
    }
}

void QtOpenGL::keyPressEvent(QKeyEvent* event)
{
    if (GetManager())
    {
        GetManager()->HandleKeyboardDown(event);
    }
}

void QtOpenGL::initializeGL()
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glOrtho(0, width(), height(), 0, 0, 1); // TODO: check

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glEnable(GL_TEXTURE_2D);

    glClearColor(0, 0, 0, 0);

    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_BLEND);
}

void QtOpenGL::paintGL()
{

}

void QtOpenGL::resizeGL(int width, int height)
{
    if (GetScreen())
    {
        GetScreen()->PerformSizeUpdate();
    }
}

QtOpenGL* widget = nullptr;

QtOpenGL* GetGLWidget()
{
    return widget;
}

void MakeCurrentGLContext()
{
    widget->makeCurrent();
}

void SetGLContext(QtOpenGL* new_widget)
{
    widget = new_widget;
}

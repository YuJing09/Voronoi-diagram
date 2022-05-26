// Project8.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include <gl/glut.h>

using namespace std;

struct vertex {
    int x;
    int y;
};

struct line {
    vertex i;
    vertex e;
};
void init(void)

{

    glClearColor(0.0, 0.0, 0.0, 0.0);//设置背景颜色为黑色

    glShadeModel(GL_SMOOTH);//设置为光滑明暗模式
    glMatrixMode(GL_PROJECTION);
    glOrtho(0.0f, (float)500, (float)500, 0.0f, 0.0, 1.0);
}

void myDisplay(void)

{
    
    glClear(GL_COLOR_BUFFER_BIT);// 将缓存清除为预先的设置值,即黑色

    //glTranslatef(0.8, 0.0, 0.0);//平移函数，暂时可以不用
    glPointSize(3);
    glBegin(GL_POINTS);
    glColor3f(1.0, 1.0, 0.0);
    glVertex2f(250., 250.);
    
    glEnd();
    

    glFlush();//强制OpenGL函数在有限时间内运行

}


void mouseClicks(int button, int state, int x, int y) {
    
    
    
    float midx, midy,s;
    float ex;
    float ix;
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        
        
        glPointSize(3);
        glBegin(GL_POINTS);
        glColor3f(1.0, 0.0, 0.0);
        glVertex2f(x,y);
       
        glEnd();
        cout << x << y << endl;
        s = -1*pow(float(250 - y) / float(250 - x),-1);
        midx = (250 + x) / 2;
        midy = (250 + y) / 2;
        cout << s << endl;
        ex =midx+ (500 - midy) / s;
        ix = midx + (-midy) / s;
        glBegin(GL_LINES);
        glLineWidth(3);
        glVertex2f(ex, 500);
        glVertex2f(ix, 0);
        glEnd();
        glFlush();
        
    }
}

int main(int argc, char** argv)

{

    /*初始化*/

    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);//单缓冲、RGB模式

    glutInitWindowSize(500, 500);

    glutInitWindowPosition(0,0);
    
    glutCreateWindow("三角形");//窗口标题

    init();

    /*绘制与显示*/

   
    glutMouseFunc(mouseClicks);
    glutDisplayFunc(myDisplay);//显示绘制图形
    
    glutMainLoop();//循环

    return(0);

}


// 執行程式: Ctrl + F5 或 [偵錯] > [啟動但不偵錯] 功能表
// 偵錯程式: F5 或 [偵錯] > [啟動偵錯] 功能表

// 開始使用的提示: 
//   1. 使用 [方案總管] 視窗，新增/管理檔案
//   2. 使用 [Team Explorer] 視窗，連線到原始檔控制
//   3. 使用 [輸出] 視窗，參閱組建輸出與其他訊息
//   4. 使用 [錯誤清單] 視窗，檢視錯誤
//   5. 前往 [專案] > [新增項目]，建立新的程式碼檔案，或是前往 [專案] > [新增現有項目]，將現有程式碼檔案新增至專案
//   6. 之後要再次開啟此專案時，請前往 [檔案] > [開啟] > [專案]，然後選取 .sln 檔案

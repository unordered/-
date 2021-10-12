using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Diagnostics;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace 프로카데미과제
{
    public partial class Form1 : Form
    {
        Stopwatch stopwatch = new Stopwatch(); //객체 선언

        public Form1()
        {
            InitializeComponent();
            dotCheck = new int[Size.Width, Size.Height];
            fillDot = new int[Size.Width, Size.Height];
            Console.WriteLine($"가로 길이 {Size.Width}, 세로길이 {Size.Height}");
            g = CreateGraphics();

        }
        int[,] dotCheck;
        int[,] fillDot;
        bool UsedDotCheck = false;


        Queue<Tuple<int, int>> tuples = new Queue<Tuple<int, int>>();

        


        private void Form1_MouseClick(object sender, MouseEventArgs e)
        {
            Console.WriteLine("마우스 클릭");
            if(fill == true)
            {
                stopwatch.Start(); // 시간측정 시작
                fill = false;
                // 채우기 알고리즘 실행
                Console.WriteLine("채우기 알고리즘 실행");
                //  recursivePointing(e.X, e.Y);
                DrawFill(e.X, e.Y);
                stopwatch.Stop(); //시간측정 끝

                System.Console.WriteLine("time : " +
                                   stopwatch.ElapsedMilliseconds + "ms");

                stopwatch.Reset();
            }
        }

        private void DrawFill(int xPos, int yPos)
        {
            tuples.Enqueue(new Tuple<int, int>(xPos, yPos));


            while(tuples.Count>0)
            {
                Tuple<int,int> temp = tuples.Dequeue();
                dotCheck[temp.Item1, temp.Item2] = 1;
                g.DrawEllipse(Pens.Green, temp.Item1, temp.Item2, 1, 1);

                if (dotCheck[temp.Item1, temp.Item2-1] != 1)
                    tuples.Enqueue(new Tuple<int, int>(temp.Item1, temp.Item2-1));
                if (dotCheck[temp.Item1+1, temp.Item2] != 1)
                    tuples.Enqueue(new Tuple<int, int>(temp.Item1+1, temp.Item2));
                if (dotCheck[temp.Item1-1, temp.Item2] != 1)
                    tuples.Enqueue(new Tuple<int, int>(temp.Item1-1, temp.Item2));
                if (dotCheck[temp.Item1, temp.Item2+1] != 1)
                    tuples.Enqueue(new Tuple<int, int>(temp.Item1, temp.Item2+1));

            }

        }

        Graphics g;
        int call = 0;
        object
        private void recursivePointing(int xPos, int yPos)
        {
            call++;
            Console.WriteLine($"call : {call}");
          //  Console.WriteLine($"xPos: {xPos}, yPos: {yPos}");
            if (xPos == 0 || yPos == 0 || xPos == Size.Width || yPos == Size.Height)
            {

                call--;
                return;
            }

            if(dotCheck[xPos, yPos] == 1)
            {
                //    Console.WriteLine("return");

                call--;
                return;
            }

            g.DrawEllipse(Pens.Red, xPos, yPos, 1, 1); 
            dotCheck[xPos, yPos] = 1;


            recursivePointing(xPos , yPos - 1);
            recursivePointing(xPos - 1, yPos );
            recursivePointing(xPos + 1, yPos );
            recursivePointing(xPos, yPos + 1);



            call--;
            return;
        }


        private void Form1_MouseMove(object sender, MouseEventArgs e)
        {
            if(e.Button == MouseButtons.Left)
            {
                Console.WriteLine("마우스 드래그");
              
                for(int i=-2; i<2; i++)
                {
                    for(int j =-2; j<2; j++)
                    {
                        g.DrawEllipse(Pens.Black, e.X+i, e.Y+j, 1, 1);

                        dotCheck[e.X+i, e.Y+j] = 1;
                    }
                }
                UsedDotCheck = true;
             
            }
        }

        private void Form1_Paint(object sender, PaintEventArgs e)
        {

        }

        // 지우기
        private void button2_Click(object sender, EventArgs e)
        {
            UsedDotCheck = false;
            Invalidate();
        }

        // 다시 그리기
        private void button3_Click(object sender, EventArgs e)
        {
            if(UsedDotCheck == false)
            {
                Invalidate();
            }
            else
            {

                Graphics g = CreateGraphics();
                for (int i=0; i<dotCheck.GetLength(0); i++)
                {
                    for (int j = 0; j < dotCheck.GetLength(1); j++)
                    {
                        if (dotCheck[i,j] == 1)
                        {
                            g.DrawEllipse(Pens.Black, i, j, 1, 1);
                        }
                    }
                }
                g.Dispose();
            }
        }


        bool fill = false;
        // 채우기 
        private void button1_Click(object sender, EventArgs e)
        {
            fill = true;
        }
    }
}

using System;
using System.Diagnostics;
using System.Threading;

namespace atest
{
    class Program
    {
        void starConsole(string name,string dir)
        {
            Process process = new Process();
            try
            {
                process.StartInfo.UseShellExecute = false ;
                process.StartInfo.FileName = @"C:\Users\Administrator\source\repos\CpuAndMrmory\Debug\CpuAndMrmory.exe";
                process.StartInfo.CreateNoWindow = true;
                //process.StartInfo.RedirectStandardOutput = true;
                process.StartInfo.RedirectStandardInput = true;
                //process.StartInfo.Arguments = "905000";
                process.Start();
                process.StandardInput.WriteLine(900000);
                //process.StandardInput.WriteLine("\r");
                //string ss = process.StandardOutput.ReadToEnd();
                //process.WaitForExit();
               
            }
            catch (Exception ex)
            {
                Console.WriteLine(ex.Message);
            }
            //ProcessStartInfo info = new ProcessStartInfo();
            //info.FileName = dir;//要启动的程序外部名称  
            //info.UseShellExecute = false;
            //info.WorkingDirectory = dir;
            //info.Arguments = "905000";
            ////info.UseShellExecute = false;
            ////info.RedirectStandardError = true;
            ////info.RedirectStandardOutput = true;
            ////info.Arguments = "1009.txt";//设置外部程序的启动参数   

            //Process pro;//申明一个程序类  

            //try
            //{
            //    pro = Process.Start(info);

            //    //pro.StandardInput.WriteLine(905000);
            //}
            //catch (System.ComponentModel.WarningException e)

            //{
            //    Console.WriteLine("系統找不到指定的程序文件" + e.Message);
            //}
        }
        void closeConsole(string name)
        {
            System.Diagnostics.Process[] myProcesses = System.Diagnostics.Process.GetProcesses();

            foreach (System.Diagnostics.Process myProcess in myProcesses)
            {
                if (name == myProcess.ProcessName)
                    myProcess.Kill();//强制关闭该程序
            }

        }
        static void Main(string[] args)
        {
            Program p = new Program();
            //开启稳定cpu程序
            //Thread.Sleep(60000);
            p.starConsole("CpuAndMrmory.exe", @"C:\Users\Administrator\source\repos\CpuAndMrmory\Debug");
            
            //开启记录cpu程序
            //Thread.Sleep(60000);
            //p.starConsole("ConsoleApp3.exe", @"C:\Users\Administrator\source\repos\ConsoleApp3\ConsoleApp3\bin\Debug\netcoreapp3.1");
            ////关闭记录cpu程序
            //Thread.Sleep(60000);
            //p.closeConsole("ConsoleApp3");
            //开启任务时间计时程序
            Thread.Sleep(60000);
            p.starConsole("ConsoleApp2.exe", @"C:\Users\Administrator\source\repos\ConsoleApp2\ConsoleApp2\bin\Debug\netcoreapp3.1");
            //关闭任务时间计时程序
            Thread.Sleep(60000);
            p.closeConsole("ConsoleApp2");

            //关闭稳定cpu程序
            Thread.Sleep(60000);
            p.closeConsole("CpuAndMrmory");
        }
    }
}

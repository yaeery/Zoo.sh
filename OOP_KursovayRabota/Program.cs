using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Runtime.InteropServices;
using System.Text;

namespace OOP_KursovayRabota
{
    static class Program
    {
        [DllImport("DLL.dll", CharSet = CharSet.Ansi)]
        public static extern void Distructor();


        [DllImport("DLL.dll", CharSet = CharSet.Unicode)]
        public extern static Int64 Memory(ref IntPtr names);


        [DllImport("DLL.dll", CharSet = CharSet.Ansi)]
        public static extern void Create();


        [DllImport("DLL.dll", CharSet = CharSet.Ansi)]
        public static extern void Sort_Name();


        [DllImport("DLL.dll", CharSet = CharSet.Ansi)]
        public static extern void Sort_Volier();


        [DllImport("DLL.dll", CharSet = CharSet.Ansi)]
        public static extern void Sort_Class();


        [DllImport("DLL.dll", CharSet = CharSet.Ansi)]
        public static extern int Get_Size();


        [DllImport("DLL.dll", CharSet = CharSet.Ansi)]
        [return: MarshalAs(UnmanagedType.BStr)]
        public static extern string Get_Name(int index);


        [DllImport("DLL.dll", CharSet = CharSet.Ansi)]
        [return: MarshalAs(UnmanagedType.BStr)]
        public static extern string Get_Volier(int index);

        [DllImport("DLL.dll", CharSet = CharSet.Ansi)]
        [return: MarshalAs(UnmanagedType.BStr)]
        public static extern string Get_Class(int index);


        [DllImport("DLL.dll", CharSet = CharSet.Ansi)]
        [return: MarshalAs(UnmanagedType.BStr)]
        public static extern string Get_Days(int index);


        [DllImport("DLL.dll", CharSet = CharSet.Unicode)]   
        public static extern void Zapis_v_file([MarshalAs(UnmanagedType.LPTStr)] string stroka);


        [DllImport("DLL.dll", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.Cdecl)]
        public static extern void Zapis_v_file_obchie([MarshalAs(UnmanagedType.LPTStr)] string stroka);


        [DllImport("DLL.dll", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.Cdecl)]
        [return: MarshalAs(UnmanagedType.BStr)]
        public static extern string Animals_V_Day([MarshalAs(UnmanagedType.LPTStr)] string stroka);


        [DllImport("DLL.dll", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.Cdecl)]
        [return: MarshalAs(UnmanagedType.BStr)]
        public static extern string Cluchainay_Exckyrsiy();


        [DllImport("DLL.dll", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.Cdecl)]
        public static extern bool Proverka_Na_Den(int index, [MarshalAs(UnmanagedType.LPTStr)] string stroka);


        
        /// <summary>
        /// Главная точка входа для приложения.
        /// </summary>
        public static List<string> Names = new List<string>();
        public static List<string> Voliers = new List<string>();
        public static List<string> Classes = new List<string>();
        public static List<string> Days = new List<string>();
        public static string Stroka ="";
        public static DataGridView newdataGridView;
        [STAThread]
        static void Main()
        {
            Create();
            Application.EnableVisualStyles();
            Application.SetCompatibleTextRenderingDefault(false);
            Application.Run(new Form1());
        }
        public static void Perenos()
        {
            Names.Clear();
            Classes.Clear();
            Days.Clear();
            Voliers.Clear();
            for (int i = 0; i < Get_Size(); i++)
            {
                if (Stroka.Length > 0)
                {
                    if (Proverka_Na_Den(i, Stroka) == true)
                    {
                        Names.Add(Get_Name(i));
                        Classes.Add(Get_Class(i));
                        Days.Add(Get_Days(i));
                        Voliers.Add(Get_Volier(i));
                    }
                }
                else
                {
                    Names.Add(Get_Name(i));
                    Classes.Add(Get_Class(i));
                    Days.Add(Get_Days(i));
                    Voliers.Add(Get_Volier(i));
                }
            }
        }
    }
}

using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Security.Cryptography;

namespace ConsoleApp1
{
    internal class Program
    {
        static void Main(string[] args)
        {
            FileStream fileStream = new FileStream(AppDomain.CurrentDomain.BaseDirectory + "/tasks/" + "6 ответ(2 часть).txt", FileMode.Open, FileAccess.Read);
            DESCryptoServiceProvider cryptoServiceProvider = new DESCryptoServiceProvider();
            cryptoServiceProvider.Key = Encoding.ASCII.GetBytes("ABCDEFGH");
            cryptoServiceProvider.IV = Encoding.ASCII.GetBytes("ABCDEFGH");
            StreamReader streamReader1 = new StreamReader((Stream)new CryptoStream((Stream)fileStream, cryptoServiceProvider.CreateDecryptor(), CryptoStreamMode.Read));
            string str1 = streamReader1.ReadLine();
            streamReader1.Close();
            fileStream.Close();
            string[] words1 = str1.Split('\t');

            for (int index = 0; index < words1.Length; ++index)
            {
                words1[index] = words1[index].Remove(0, 1);
                words1[index] = words1[index].Remove(words1[index].Length - 1, 1);

            }
            foreach (string text in words1)
            {
                Console.WriteLine(text);
            }            
        }
    }
}

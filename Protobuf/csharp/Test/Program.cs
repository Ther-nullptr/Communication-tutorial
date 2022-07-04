using System;
using System.IO;
using Google.Protobuf;
using Student;

namespace example
{
    class Program
    {
        static void Main(string[] args)
        {
            // 1. 如何实例化一个proto文件中定义的类 
            var student1 = new StudentInfo();

            // 2. 如何设置类的各个属性
            // a. 添加单一字段（回忆Csharp一讲中的“字段”）
            student1.Age = 18;
            student1.Name = "Alice";
            student1.Sex = Sex.Female;

            // b. 添加repeated字段（使用Add()方法）
            var course1 = new Course();
            course1.Name = "calculus";
            course1.Credit = 5;
            student1.Courses.Add(course1);

            var course2 = new Course();
            course2.Name = "Fundamentals of Electronic Circuits and System";
            course2.Credit = 2;
            student1.Courses.Add(course2);

            // 3. 如何使用类的各个属性（回忆Csharp一讲中的“字段”）
            Console.WriteLine("----------------student info----------------");
            Console.WriteLine($"age: {student1.Age}");
            Console.WriteLine($"name: {student1.Name}");
            Console.WriteLine($"sex (0:male, 1:female): {student1.Sex}");
            Console.WriteLine($"courses: ");
            foreach (Course course in student1.Courses)
            {
                Console.WriteLine($"name: {course.Name}  credit: {course.Credit}");
            }

            // 4. 序列化
            Console.WriteLine("serialize to array.");
            byte[] data = new byte[student1.CalculateSize()];
            MemoryStream ostream = new MemoryStream();
            using (CodedOutputStream output = new CodedOutputStream(ostream, true))
            {
                student1.WriteTo(output);
                output.Flush();
            }
            data = ostream.ToArray();

            // 5. 反序列化和debug
            Console.WriteLine("deserialize from array.");
            var student2 = new StudentInfo();
            MemoryStream istream = new MemoryStream(data);
            using (CodedInputStream input = new CodedInputStream(istream))
            {
                student2?.MergeFrom(input);
            }
            Console.WriteLine(student2);
        }
    }
}
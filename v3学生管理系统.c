#include <stdio.h>
#include <string.h>
#define STUDENTS 30   
#define COURSE 6      

typedef struct {
    long id;                // 学号
    char name[20];          // 姓名
    float score[COURSE];    // 多门课程成绩
    float total;            // 总分
    float avg;              // 平均分
} Student;
//菜单
void menu()                                     
{
    printf("\n========== 学生成绩管理系统 V3.0 ==========\n");
    printf("1. Input record\n");
    printf("2. Calculate total and average score of every course\n");
    printf("3. Calculate total and average score of every student\n");
    printf("4. Sort in descending order by total score\n");
    printf("5. Sort in ascending order by total score\n");
    printf("6. Sort in ascending order by number\n");
    printf("7. Sort in dictionary order by name\n");
    printf("8. Search by number\n");
    printf("9. Search by name\n");
    printf("10. Statistic analysis\n");
    printf("11. List record\n");
    printf("0. Exit\n");
    printf("==========================================\n");
    printf("Please enter your choice: ");
}
//1.录入学生信息
void inputRecord(Student stu[], int m, int n)   
{
    for(int i=0; i<n;i++)
    {
        printf("请输入第%d个学生的学号：", i+1);
        scanf("%ld", &stu[i].id);
        printf("请输入第%d个学生的姓名：", i+1);
        scanf("%s", stu[i].name);
        for(int j=0; j<m; j++)
        {
            printf("请输入第%d个学生的第%d门课程成绩：", i+1, j+1);
            scanf("%f", &stu[i].score[j]);
        }
    }
}
//2.计算每门课程总分 & 平均分
void calcCourseTotalAvg(Student stu[], int n, int m, float courseTotal[], float courseAvg[]) 
{
    for (int i = 0; i < m; i++) 
    {
        courseTotal[i] = 0;
        for (int j = 0; j < n; j++) 
        {
            courseTotal[i] += stu[j].score[i];
        }
        courseAvg[i] = courseTotal[i] / n;
    }

    printf("\n==================== 每门课程总分 & 平均分 ====================\n");
    printf("课程\t总分\t\t平均分\n");
    printf("================================================================\n");
    for (int i = 0; i < m; i++) {
        printf("课程%d\t%.2f\t\t%.2f\n", i + 1, courseTotal[i], courseAvg[i]);
    }
    printf("================================================================\n");
}
//3.计算每个学生总分 & 平均分
void calcStuTotalAvg(Student stu[], int n, int m) 
{
    for (int i = 0; i < n; i++) 
    {
        float sum = 0;
        for (int j = 0; j < m; j++) 
        {
            sum += stu[i].score[j];
        }
        stu[i].total = sum;
        stu[i].avg = sum / m;
    }
}
//4. 按总分降序排序
void resortTotal(Student stu[], int n, int m) 
{
    for (int i = 0; i < n - 1; i++) 
    {
        for (int j = 0; j < n - i - 1; j++) 
        {
            if (stu[j].total < stu[j + 1].total) 
            {
                Student temp = stu[j];
                stu[j] = stu[j + 1];
                stu[j + 1] = temp;
            }
        }
    }

    printf("\n==================== 按总分降序排名 ====================\n");
    printf("名次\t学号\t姓名\t");
    for (int k = 0; k < m; k++) printf("课程%d\t", k + 1);
    printf("总分\t平均分\n");
    printf("===========================================================\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%ld\t%s\t", i + 1, stu[i].id, stu[i].name);
        for (int k = 0; k < m; k++) printf("%.1f\t", stu[i].score[k]);
        printf("%.1f\t%.1f\n", stu[i].total, stu[i].avg);
    }
}
//5. 按总分升序排序
void sortTotal(Student stu[], int n, int m) 
{
    for (int i = 0; i < n - 1; i++) 
    {
        for (int j = 0; j < n - i - 1; j++) 
        {
            if (stu[j].total > stu[j + 1].total) 
            {
                Student temp = stu[j];
                stu[j] = stu[j + 1];
                stu[j + 1] = temp;
            }
        }
    }

    printf("\n==================== 按总分升序排名 ====================\n");
    printf("名次\t学号\t姓名\t");
    for (int k = 0; k < m; k++) printf("课程%d\t", k + 1);
    printf("总分\t平均分\n");
    printf("===========================================================\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%ld\t%s\t", i + 1, stu[i].id, stu[i].name);
        for (int k = 0; k < m; k++) printf("%.1f\t", stu[i].score[k]);
        printf("%.1f\t%.1f\n", stu[i].total, stu[i].avg);
    }
}
//6. 按学号升序排序
void sortId(Student stu[], int n, int m) 
{
    for (int i = 0; i < n - 1; i++) 
    {
        for (int j = 0; j < n - i - 1; j++) 
        {
            if (stu[j].id > stu[j + 1].id) 
            {
                Student temp = stu[j];
                stu[j] = stu[j + 1];
                stu[j + 1] = temp;
            }
        }
    }

    printf("\n==================== 按学号升序排序 ====================\n");
    printf("学号\t姓名\t");
    for (int k = 0; k < m; k++) printf("课程%d\t", k + 1);
    printf("总分\t平均分\n");
    printf("===========================================================\n");
    for (int i = 0; i < n; i++) {
        printf("%ld\t%s\t", stu[i].id, stu[i].name);
        for (int k = 0; k < m; k++) printf("%.1f\t", stu[i].score[k]);
        printf("%.1f\t%.1f\n", stu[i].total, stu[i].avg);
    }
}
//7. 按姓名字典序排序
void sortName(Student stu[], int n, int m) 
{
    for (int i = 0; i < n - 1; i++) 
    {
        for (int j = 0; j < n - i - 1; j++) 
        {
            if (strcmp(stu[j].name, stu[j + 1].name) > 0) 
            {
                Student temp = stu[j];
                stu[j] = stu[j + 1];
                stu[j + 1] = temp;
            }
        }
    }

    printf("\n==================== 按姓名字典序排序 ====================\n");
    printf("学号\t姓名\t");
    for (int k = 0; k < m; k++) printf("课程%d\t", k + 1);
    printf("总分\t平均分\n");
    printf("===========================================================\n");
    for (int i = 0; i < n; i++) {
        printf("%ld\t%s\t", stu[i].id, stu[i].name);
        for (int k = 0; k < m; k++) printf("%.1f\t", stu[i].score[k]);
        printf("%.1f\t%.1f\n", stu[i].total, stu[i].avg);
    }
}
//8. 按学号查询
void searchById(Student stu[], int n, int m) 
{
    long searchId;
    printf("请输入要查询的学号：");
    scanf("%ld", &searchId);
    int found = 0;
    for (int i = 0; i < n; i++) 
    {
        if (stu[i].id == searchId) 
        {
            found = 1;
            int rank = 1;
            for (int j = 0; j < n; j++) 
            {
                if (stu[j].total > stu[i].total) rank++;
            }

            printf("\n==================== 查询结果 ====================\n");
            printf("学号\t姓名\t排名\t总分\t平均分\n");
            printf("=======================================================\n");
            printf("%ld\t%s\t%d\t%.1f\t%.1f\n", stu[i].id, stu[i].name, rank, stu[i].total, stu[i].avg);
            printf("各科成绩：");
            for (int k = 0; k < m; k++) printf("%.1f  ", stu[i].score[k]);
            printf("\n=======================================================\n");
            break;
        }
    }
    if (!found) printf("未找到该学号\n");
}
//9. 按姓名查询
void searchByName(Student stu[], int n, int m) 
{
    char searchName[20];
    printf("请输入要查询的姓名：");
    scanf("%s", searchName);
    int found = 0;
    for (int i = 0; i < n; i++) 
    {
        if (strcmp(stu[i].name, searchName) == 0) 
        {
            found = 1;
            int rank = 1;
            for (int j = 0; j < n; j++) 
            {
                if (stu[j].total > stu[i].total) rank++;
            }

            printf("\n==================== 查询结果 ====================\n");
            printf("学号\t姓名\t排名\t总分\t平均分\n");
            printf("=======================================================\n");
            printf("%ld\t%s\t%d\t%.1f\t%.1f\n", stu[i].id, stu[i].name, rank, stu[i].total, stu[i].avg);
            printf("各科成绩：");
            for (int k = 0; k < m; k++) printf("%.1f  ", stu[i].score[k]);
            printf("\n=======================================================\n");
            break;
        }
    }
    if (!found) printf("未找到该姓名\n");
}
//10. 成绩统计分析
void statisticAnalysis(Student stu[], int n, int m) 
{
    for (int j = 0; j < m; j++) 
    {
        int A = 0, B = 0, C = 0, D = 0, E = 0;
        for (int i = 0; i < n; i++) 
        {
            float s = stu[i].score[j];
            if (s >= 90) A++;
            else if (s >= 80) B++;
            else if (s >= 70) C++;
            else if (s >= 60) D++;
            else E++;
        }

        printf("\n==================== 第%d门课程统计 ====================\n", j + 1);
        printf("等级\t\t人数\t占比\n");
        printf("===========================================\n");
        printf("优秀(90-100)\t%d\t%.2f%%\n", A, (float)A / n * 100);
        printf("良好(80-89)\t%d\t%.2f%%\n", B, (float)B / n * 100);
        printf("中等(70-79)\t%d\t%.2f%%\n", C, (float)C / n * 100);
        printf("及格(60-69)\t%d\t%.2f%%\n", D, (float)D / n * 100);
        printf("不及格(0-59)\t%d\t%.2f%%\n", E, (float)E / n * 100);
        printf("===========================================\n");
    }
}
//11. 输出所有记录
void listRecord(Student stu[],int n,int m,float courseTotal[],float courseAvg[]) 
{
    printf("\n==================== 所有学生成绩详情表 ====================\n");
    printf("学号\t姓名\t");
    for (int k = 0; k < m; k++) {
        printf("课程%d\t", k + 1);
    }
    printf("总分\t平均分\n");
    printf("===========================================================\n");
    for (int i = 0; i < n; i++) {
        printf("%ld\t%s\t", stu[i].id, stu[i].name);
        for (int k = 0; k < m; k++) {
            printf("%.1f\t", stu[i].score[k]);
        }
        printf("%.1f\t%.1f\n", stu[i].total, stu[i].avg);
    }
}
int main()
{
    Student stu[STUDENTS];
    int m,n;
    int choice;
    float courseTotal[COURSE],courseAvg[COURSE];
    do {menu();
    scanf("%d", &choice);
    switch (choice)
    {
        case 0:
            printf("退出...\n");
            return 0;
        case 1:
            printf("请输入学生人数：");
            scanf("%d", &n);
            printf("请输入课程数量：");
            scanf("%d", &m);
            if(n == 0||m == 0||n<0||m<0||n>STUDENTS||m>COURSE) {
                printf("输入数据有误，请重新输入。\n");
                break;}
            inputRecord(stu,m,n);
            break;
        case 2:
            if(n == 0||m == 0||n<0||m<0||n>STUDENTS||m>COURSE) {
                printf("输入数据有误，请重新输入。\n");
                break;}
            calcCourseTotalAvg(stu, n, m, courseTotal, courseAvg);
            break;
        case 3:
            if(n == 0||m == 0||n<0||m<0||n>STUDENTS||m>COURSE) {
                printf("输入数据有误，请重新输入。\n");
                break;}
            calcStuTotalAvg(stu, n, m);
            break;
        case 4:
            if(n == 0||m == 0||n<0||m<0||n>STUDENTS||m>COURSE) {
                printf("输入数据有误，请重新输入。\n");
                break;}
            resortTotal(stu, n, m);
            break;
        case 5:
            if(n == 0||m == 0||n<0||m<0||n>STUDENTS||m>COURSE) {
                printf("输入数据有误，请重新输入。\n");
                break;}
            sortTotal(stu, n, m);
            break;
        case 6:
            if(n == 0||m == 0||n<0||m<0||n>STUDENTS||m>COURSE) {
                printf("输入数据有误，请重新输入。\n");
                break;}
            sortId(stu, n, m);
            break;
        case 7:
            if(n == 0||m == 0||n<0||m<0||n>STUDENTS||m>COURSE) {
                printf("输入数据有误，请重新输入。\n");
                break;}
            sortName(stu, n, m);
            break;
        case 8:
            if(n == 0||m == 0||n<0||m<0||n>STUDENTS||m>COURSE) {
                printf("输入数据有误，请重新输入。\n");
                break;}
            searchById(stu, n, m);
            break;
        case 9:
            if(n == 0||m == 0||n<0||m<0||n>STUDENTS||m>COURSE) {
                printf("输入数据有误，请重新输入。\n");
                break;} 
            searchByName(stu, n, m);
            break;
        case 10:
            if(n == 0||m == 0||n<0||m<0||n>STUDENTS||m>COURSE) {
                printf("输入数据有误，请重新输入。\n");
                break;}
            statisticAnalysis(stu, n, m);
            break;
        case 11:
            if(n == 0||m == 0||n<0||m<0||n>STUDENTS||m>COURSE) {
                printf("输入数据有误，请重新输入。\n");
                break;}
            listRecord(stu, n, m, courseTotal, courseAvg);
            break;
        default:
            printf("无效选项，请重新尝试\n");

    }
    } while (choice != 0);
    return 0;
}
#include<stdio.h>
#define STUDENTS 30
#define COURSE 6

void inputRecord(long id[], float score[][COURSE], int n ,int m, char name[STUDENTS][20])        //1.录入学生学号和成绩
{
    for(int i=0; i<n;i++)
{
    printf("请输入第%d个学生的学号：", i+1);
    scanf("%ld", id+i);
    printf("请输入第%d个学生的姓名：", i+1);
    scanf("%s", name+i);
    for(int j=0; j<m; j++)
    {
        printf("请输入第%d个学生的第%d门课程成绩：", i+1, j+1);
        scanf("%f", &score[i][j]);
    }
}
}

void scoreSumAvg(float score[][COURSE], int n, int  m, float courseTotal[], float avg[])         //2. 计算每门课程的总分和平均分
{
    for(int j=0; j<m; j++)
    {
        courseTotal[j] = 0;
        avg[j] = 0;
        for(int i=0; i<n; i++)
            {
                courseTotal[j] += score[i][j];
            }
            avg[j] = courseTotal[j] / n;
        
    }
    printf("\n==================== 各课程总分 & 平均分 ====================\n");
    printf("课程编号\t总分\t\t平均分\n");
    printf("============================================================\n");
    
    for(int j=0; j<m; j++)
    {
        printf("课程%d\t\t%.2f\t\t%.2f\n", j+1, courseTotal[j], avg[j]);
    }
    printf("============================================================\n");
}

void ranking(float score[][COURSE],long id[],char name[STUDENTS][20], int n, int m)              //3. 按成绩由高到低排序
{
    float total[STUDENTS];  //计算总分
    for(int i=0; i<n; i++){
        float sum = 0;
        for(int k=0; k<m; k++){
            sum += score[i][k];
        }
        total[i] = sum;
    }
    for(int i = 0; i < n-1; i++) {// 冒泡排序，按照总分从高到低排序
        for(int j = 0; j < n-i-1; j++) {
            if(total[j] < total[j+1]) {
                // 交换总分
                float tempTotal = total[j];
                total[j] = total[j+1];
                total[j+1] = tempTotal;

                // 交换所有课程成绩
                for(int k = 0; k < m; k++) {
                    float temp = score[j][k];
                    score[j][k] = score[j+1][k];
                    score[j+1][k] = temp;
                }

                // 交换学号
                long tempId = id[j];
                id[j] = id[j+1];
                id[j+1] = tempId;

                // 交换姓名
                char tempName[20];
                for(int k = 0; k < 20; k++) {
                    tempName[k] = name[j][k];
                    name[j][k] = name[j+1][k];
                    name[j+1][k] = tempName[k];
                }
            }
        }
    }

    printf("\n==================== 学生成绩名次表 ====================\n");
    printf("名次\t学号\t姓名\t");
    for(int k=0; k<m; k++) 
        {printf("课程%d\t", k+1);}
    printf("总分\n");
    printf("========================================================\n");

    for(int i=0; i<n; i++) {
        printf("%d\t%ld\t%s\t", i+1, id[i], name[i]);
        for(int k=0; k<m; k++) 
            {printf("%.1f\t", score[i][k]);}
        printf("%.1f\n", total[i]);
    }
}

void reversedranking(float score[][COURSE], long id[], char name[STUDENTS][20], int n, int m)    //4. 按成绩由低到高排序
{
    float total[STUDENTS];  //计算总分
    for(int i=0; i<n; i++){
        float sum = 0;
        for(int k=0; k<m; k++){
            sum += score[i][k];
        }
        total[i] = sum;
    }
    for(int i = 0; i < n-1; i++) {// 冒泡排序，按照总分从低到高排序
        for(int j = 0; j < n-i-1; j++) {
            if(total[j] > total[j+1]) {
                // 交换总分
                float tempTotal = total[j];
                total[j] = total[j+1];
                total[j+1] = tempTotal;
                
                // 交换所有课程成绩
                for(int k = 0; k < m; k++) {
                    float temp = score[j][k];
                    score[j][k] = score[j+1][k];
                    score[j+1][k] = temp;
                }

                // 交换学号
                long tempId = id[j];
                id[j] = id[j+1];
                id[j+1] = tempId;

                // 交换姓名
                char tempName[20];
                for(int k = 0; k < 20; k++) {
                    tempName[k] = name[j][k];
                    name[j][k] = name[j+1][k];
                    name[j+1][k] = tempName[k];
                }
            }
        }
    }

    printf("\n==================== 学生成绩倒数名次表 ====================\n");
    printf("名次\t学号\t姓名\t");
    for(int k=0; k<m; k++) 
        {printf("课程%d\t", k+1);}
    printf("总分\n");
    printf("============================================================\n");

    for(int i=0; i<n; i++) {
        printf("%d\t%ld\t%s\t", n-i, id[i], name[i]);
        for(int k=0; k<m; k++) 
            {printf("%.1f\t", score[i][k]);}
        printf("%.1f\n", total[i]);
    }
}

void menu() {                                                                                    // 打印菜单
    printf("\n====== 学生成绩管理系统 ======\n");
    printf("1. Input record\n");
    printf("2. Calculate total and average score of course\n");
    printf("3. Sort in descending order by score\n");
    printf("4. Sort in asending order by score\n");
    printf("5. Sort in ascending order by number\n");
    printf("6. Search by number\n");
    printf("7. Statistic analysis\n");
    printf("8. List record\n");
    printf("0. Exit\n");
    printf("==============================\n");
    printf("Please enter your choice:");
}

int compareId(long* a,long* b)                                                                   // 学号比较函数
        {if(*a>*b)
            return 1;
        else if(*a<*b)
            return -1;
        else
            return 0;
        }

void IDsort(long id[], float score[][COURSE], int n, int m,char name[STUDENTS][20])              //5.按学号由小到大排序
{
    for(int i=0; i<n-1; i++)//冒泡排序
    {
        for(int j=0; j<n-i-1; j++)
        {
            if(compareId(id+(j),id+(j+1))>0)
            {
                float tempscore;
                tempscore=score[i][j];
                score[i][j]=score[i][j+1];
                score[i][j+1]=tempscore;
                
                long tempid;
                tempid=id[j];
                id[j]=id[j+1];
                id[j+1]=tempid;

                char tempName[20];
                for(int k=0; k<20; k++)
                {
                    tempName[k] = name[j][k];
                    name[j][k] = name[j+1][k];
                    name[j+1][k] = tempName[k];
                }
                
                for(int k=0; k<m; k++)
                {
                    float tempScore = score[j][k];
                    score[j][k] = score[j+1][k];
                    score[j+1][k] = tempScore;
                }
            }
        }
    }
    printf("\n==================== 按学号排序成绩表 ====================\n");
    printf("学号\t\t姓名\t");
    for(int k=0; k<m; k++)
        {printf("课程%d\t", k+1);}
    printf("\n==========================================================\n");

    for(int i=0; i<n; i++)
    {
        printf("%ld\t\t%s\t", id[i], name[i]);
        for(int k=0; k<m; k++)
            {printf("%.1f\t", score[i][k]);}
        printf("\n");
    }
}

void IDsearch(long id[], float score[][COURSE], int n, int m,char name[STUDENTS][20])            //6. 按学号查询成绩与排名
{
    printf("请输入要查询的学号：");
    long searchid;
    while (scanf("%ld", &searchid) != 1)
    {
        // 清空缓冲区垃圾
        while (getchar() != '\n');
        printf("\n输入错误！请输入数字学号：");
    }
    int found = 0;
    for(int i=0; i<n; i++)//遍历学号数组查找匹配的学号
    { 
        if(id[i]==searchid)//如果找到匹配的学号 
        {   found = 1;
            float total = 0;//计算总分
            for(int k=0; k<m; k++)
                {total += score[i][k];}
            int rank = 1;//算排名
            for(int j=0; j<n;j++)//遍历总分数组比较成绩排名
                {float otherTotal = 0;//重置其他学生总分
                for(int k=0; k<m; k++)//计算其他学生总分
                    {otherTotal += score[j][k];}
                if(otherTotal>total)//如果其他学生总分比查询学生总分高，排名加1
                    rank++;
                }
            printf("\n==================== 查询结果 ====================\n");
            printf("学号\t\t姓名\t\t总分\t\t排名\n");
            printf("====================================================\n");
            printf("%ld\t\t%s\t\t%.1f\t\t%d\n", id[i], name[i], total, rank);
            printf("====================================================\n\n");
            break;//找到后退出循环
        }
    }
    if(!found)//未找到
    {printf("未找到该学号对应的学生信息。\n");}
}

void statisticAnalysis(float score[][COURSE], int n, int m)                                      //7. 统计分析
{
    for (int j = 0; j < m; j++)
    {
        int A = 0;  // A 90~100
        int B = 0;  // B 80~89
        int C = 0;  // C 70~79
        int D = 0;  // D 60~69
        int E = 0;  // E 0~59

        for (int i = 0; i < n; i++)
        {
            float s = score[i][j];
            if (s >= 90)
                A++;
            else if (s >= 80)
                B++;
            else if (s >= 70)
                C++;
            else if (s >= 60)
                D++;
            else
                E++;
        }

        printf("\n==================== 第%d门课程成绩统计 ====================\n", j + 1);
        printf("等级\t\t人数\t\t占比\n");
        printf("==========================================================\n");
        printf("A(90-100)\t%d\t\t%.2f%%\n", A, (float)A / n * 100);
        printf("B(80-89)\t%d\t\t%.2f%%\n", B, (float)B / n * 100);
        printf("C(70-79)\t%d\t\t%.2f%%\n", C, (float)C / n * 100);
        printf("D(60-69)\t%d\t\t%.2f%%\n", D, (float)D / n * 100);
        printf("E(0-59)\t\t%d\t\t%.2f%%\n", E, (float)E / n * 100);
        printf("==========================================================\n");
    }
}

void listRecord(float score[][COURSE], long id[], char name[STUDENTS][20], int n, int m, float courseTotal[], float avg[]) 
{
    printf("\n==================== 所有学生成绩详情表 ====================\n");
    printf("学号\t姓名\t");
    for (int k = 0; k < m; k++) {
        printf("课程%d\t", k + 1);
    }
    printf("总分\t平均分\n");
    printf("===============================================================\n");

    for (int i = 0; i < n; i++) {
        float total = 0;
        for (int k = 0; k < m; k++) {
            total += score[i][k];
        }
        float stuAvg = total / m;

        printf("%ld\t%s\t", id[i], name[i]);
        for (int k = 0; k < m; k++) {
            printf("%.1f\t", score[i][k]);
        }
        printf("%.1f\t%.1f\n", total, stuAvg);
    }

    printf("\n==================== 每门课程总分 & 平均分 ====================\n");
    for (int j = 0; j < m; j++) {
        printf("课程%d：总分:%.2f，平均分:%.2f\n", j + 1, courseTotal[j], avg[j]);
    }
    printf("===============================================================\n");
}

int main()
{
    int n;
    int m;
    char name[STUDENTS][20];
    long id[STUDENTS];
    float score[STUDENTS][COURSE];
    float courseTotal[COURSE],avg[COURSE];
    int choice;
    do {menu();
    scanf("%d", &choice);
    switch (choice)
    {
        case 0:
            printf("退出...\n");
            return 0;
        case 1:
            printf("请输入学生人数（0-%d）：", STUDENTS);
            scanf("%d", &n);
            printf("请输入科目数量（0-%d）：", COURSE);
            scanf("%d", &m);
            if(n == 0||m == 0||n<0||m<0||n>STUDENTS||m>COURSE) {
                printf("输入数据有误，请重新输入。\n");
                break;}
            inputRecord(id, score, n, m, name);
            // 录入学生学号和成绩
            break;
        case 2:
            if(n == 0||m == 0||n<0||m<0||n>STUDENTS||m>COURSE) {
                printf("输入数据有误，请重新输入。\n");
            }
            else {
            scoreSumAvg(score, n, m, courseTotal, avg);
            }
            // 计算总分和平均分
            break;
        case 3:
            if(n == 0||m == 0||n<0||m<0||n>STUDENTS||m>COURSE) {
                printf("输入数据有误，请重新输入。\n");
            }
            else
            {ranking(score, id, name, n, m);
            }
            // 按成绩由高到低排序
            break;
        case 4:
            if(n == 0||m == 0||n<0||m<0||n>STUDENTS||m>COURSE) {
                printf("输入数据有误，请重新输入。\n");
            }
            else
            {reversedranking(score, id, name, n, m);
            }
            // 按成绩由低到高排序
            break;
        case 5:
            if(n == 0||m == 0||n<0||m<0||n>STUDENTS||m>COURSE) {
                printf("输入数据有误，请重新输入。\n");
            }
            else
            {IDsort(id, score, n, m, name);
            }
            // 按学号由小到大排序
            break;
        case 6:
            if(n == 0||m == 0||n<0||m<0||n>STUDENTS||m>COURSE) {
                printf("输入数据有误，请重新输入。\n");
            }
            else
            {IDsearch(id, score, n, m, name);
            }
            // 按学号查询成绩与排名
            break;
        case 7:
            if(n == 0||m == 0||n<0||m<0||n>STUDENTS||m>COURSE) {
                printf("输入数据有误，请重新输入。\n");
            }
            else    
            {statisticAnalysis(score, n, m);
            }
            // 统计分析
            break;
        case 8:
            if(n == 0||m == 0||n<0||m<0||n>STUDENTS||m>COURSE) {
                printf("输入数据有误，请重新输入。\n");
            }
            else
            {listRecord(score, id, name, n, m, courseTotal, avg);
            }
            // 输出所有学生信息（学号、姓名、各科成绩、总分、平均分）+ 每门课总分、平均分
            break;
        default:
            printf("无效选择。请重新尝试。\n");
        
    }
    } while (choice != 0);
    return 0;
}    
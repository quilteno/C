//定义二维世界
int world[152][152] = { 0 };
//定义活细胞和无细胞区域的图案
int IMAGE, imgLive, imgEmpty;
//绘制有生命世界的图案
SetWorkingImage(&imgLive);//设定当前的绘图设备
setcolor(GREEN);//设置当前绘图前景色
setfillstyle(GREEN);//设置当前填充样式
fillellipse(0,0,3,3);//画填充的椭圆（有边框）

//绘制无生命世界的图案
SetWorkingImage(&imgEmpty);
setcolor(DARKGRAY);
rectangle(1, 1, 2, 2);

//恢复对默认窗口的绘制
SetWorkingImage(NULL);
//进化
void Evolution()
{
    __int8 tmp[152][152] = { 0 };
    int sum;

    for (int x = 0; x < 150; x++)
    {
        for (int y = 0; y < 150; y++)
        {
            //计算周围活着的生命数量
            sum = world[x + 1][y] + world[x + 1][y - 1] + world[x][y - 1] + world[x - 1][y - 1]
                + world[x - 1][y] + world[x - 1][y + 1] + world[x][y + 1] + world[x + 1][y - 1];

            //计算当前位置的生命状态
            switch (sum)
            {
            case 3:tmp[x][y] = 1; break;
            case 2:tmp[x][y] = world[x][y]; break;
            default:tmp[x][y] = 0; break;
            }
        }
    }

    //将临时数组恢复为世界
    memcpy(world, tmp, 152 * 152 * sizeof(__int8));
}
//创建细胞随机的世界
void RandWorld() 
{
    for (int x = 0; x < 150; x++)
    {
        for (int y = 0; y < 150; y++)
        {
            world[x][y] = rand() % 2;
        }
    }
}
//创建一个细胞以方形分布的世界
void SquareWorld()
{
    memset(world, 0, 152 * 152 * sizeof(__int8));

    for (int x = 1; x <= 150; x++)
        world[x][1] = world[x][150] = 1;

    for (int y = 1; y <= 150; y++)
        world[1][y] = world[150][y] = 1;
}
//绘制世界
void PaintWorld()
{
    for (int x = 1; x <= 150; x++)
        for (int y = 1; y <= 150; y++)
            //在当前设备上绘制指定图像
            putimage(16+x*4,16+y*4,world[x][y]?&imgLive:&imgEmpty);

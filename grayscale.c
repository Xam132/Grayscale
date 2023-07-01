#include<stdio.h>
int main(){
    int width=0;
    int height=0;
    FILE* file1 = fopen("D:/vscode files/code files/imageworks/house.ppm","rb"); // Input file
    FILE* file2 = fopen("D:/vscode files/code files/imageworks/greyhouse.ppm","wb"); // Output file
    if(file1==NULL){
        printf("Error opening the file.\n");
        return 1;
    }
    char format[3];
    fscanf(file1,"%2s",format);
    if(format[0]!='P' || format[1]!='6'){
        printf("Invalid file format.\n");
        return 1;
    }
    fscanf(file1, "%d %d", &width, &height);
    fgetc(file1);
    int colorVal;
    fscanf(file1,"%d",&colorVal);
    if(colorVal!=255){
        printf("Invalid maximum colour value: Expected 255.\n");
        return 1;
    }
    fgetc(file1);
    fprintf(file2, "P6\n%d %d\n255\n", width, height);
    unsigned char pixel[3];
    for(int y=0;y<height;y++){
        for(int x=0;x<width;x++){
            fread(pixel, 1, 3, file1);
            int r=pixel[0];
            int g=pixel[1];
            int b=pixel[2];
            int a=(r+g+b)/3;
            unsigned char newPixel[] = { a, a, a };
            fwrite(newPixel, 1, 3, file2);
        }
    }
    fclose(file1);
    fclose(file2);
    printf("Greyscale of Image created successfully.\n");
    return 0;
}
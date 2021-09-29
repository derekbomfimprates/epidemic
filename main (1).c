#include<stdio.h>
#include<stdlib.h>
#include<math.h>

main()
{
    float t2=0.10, t1=0.000, e=0.1,s=8.95, i=1.05,r=0.0, p, dS=0.0, dI=0.0, dR=0.0, t2p, t1p, sp, ip, rp, Ifinal1, Ifinal2, w=4.0*3.1415926535897932384;
    int cont;
    FILE *ptt;
	FILE *pts;
    FILE *pti;
    FILE *ptr;
    FILE *ptp;


    ptt=fopen("Time.txt", "w");
    pts=fopen("Susceptible.txt","w");
    pti=fopen("Infected.txt","w");
    ptr=fopen("Removed.txt","w");
    ptp=fopen("Vaccination population.txt","w");


	if(ptt==NULL)
    {
        printf("Erro na execucao do arquivo");
        exit(0);
    }
   if(pts==NULL)
    {
        printf("Erro na execucao do arquivo");
        exit(0);
    }
    if(pti==NULL)
    {
        printf("Erro na execucao do arquivo");
        exit(0);
    }
    if(ptr==NULL)
    {
        printf("Erro na execucao do arquivo");
        exit(0);
    }
    if(ptp==NULL)
    {
        printf("Erro na execucao do arquivo");
        exit(0);
    }



    float B=4.0, y=1.2, a=1.0;

        fprintf(pts,"\n \n \n");
        fprintf(pti,"\n \n \n");
        fprintf(ptr,"\n \n \n");
        fprintf(ptt,"\n \n \n");
        fprintf(ptp,"\n \n \n");

	while(t2<=100.0)
    {
        t1p=t1;
        t2p=t2;
        sp=s;
        ip=i;
        rp=r;
        for(cont=0; cont<20; cont++){
            p=0.5;
            dS=((1.0-p)*y-(B*i+y)*s)*(t2-t1);
            dI=(B*i*s-(y+a)*i)*(t2-t1);
            dR=(a*i+(p-r)*y)*(t2-t1);
            s=s+dS;
            i=i+dI;
            r=r+dR;
            t2=t2+e;
            t1=t1+e;
            }
            Ifinal1=i;
            t1=t1p;
            t2=t2p;
            s=sp;
            i=ip;
            r=rp;

          for(cont=0; cont<20; cont++){
            if(cos(w*t1)<=0.0){
                p=0.0;
            }
            else{
                p=0.5*cos(w*t1);
            }

            dS=((1.0-p)*y-(B*i+y)*s)*(t2-t1);
            dI=(B*i*s-(y+a)*i)*(t2-t1);
            dR=(a*i+(p-r)*y)*(t2-t1);
            s=s+dS;
            i=i+dI;
            r=r+dR;
            t2=t2+e;
            t1=t1+e;
            }

            Ifinal2=i;
            t1=t1p;
            t2=t2p;
            s=sp;
            i=ip;
            r=rp;

            if(Ifinal1<Ifinal2){
            for(cont=0; cont<20; cont++){
            p=0.5;
            dS=((1.0-p)*y-(B*i+y)*s)*(t2-t1);
            dI=(B*i*s-(y+a)*i)*(t2-t1);
            dR=(a*i+(p-r)*y)*(t2-t1);
            s=s+dS;
            i=i+dI;
            r=r+dR;
            t2=t2+e;
            t1=t1+e;

        fprintf(pts,"%.7f \n", s);
        fprintf(pti,"%.7f  \n",i);
        fprintf(ptr,"%.7f  \n", r);
        fprintf(ptp,"%.7f\n", p);
        fprintf(ptt,"%.7f  \n",t1);
            }
            }
            else{
                for(cont=0; cont<20; cont++){
            if(cos(w*t1)<=0.0){
                p=0.0;
            }
            else{
                p=0.5*cos(w*t1);
            }

            dS=((1.0-p)*y-(B*i+y)*s)*(t2-t1);
            dI=(B*i*s-(y+a)*i)*(t2-t1);
            dR=(a*i+(p-r)*y)*(t2-t1);
            s=s+dS;
            i=i+dI;
            r=r+dR;
            t2=t2+e;
            t1=t1+e;

            fprintf(pts,"%.7f \n", s);
        fprintf(pti,"%.7f  \n",i);
        fprintf(ptr,"%.7f  \n", r);
        fprintf(ptp,"%.7f\n", p);
        fprintf(ptt,"%.7f  \n",t1);
            }
            }
            }


    fclose(pts);
    fclose(pti);
    fclose(ptr);
    fclose(ptp);
    fclose(ptt);

	system("pause");
}


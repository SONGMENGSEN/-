//**********   TD Parameters ************float r=2000;float h=0.002;//**********   ESO Parameters ************float delta=0.001;float b=2;float beta01=135;float beta02=1900;float beta03=80;//**********   NLSEF Parameters ************float alpha1=0.4;float alpha2=1.1;float beta1=1;		//比例增益float beta2=1.1;	//微分增益float ADRC(float v,float y,float u)             // v是控制系统的输入，y是控制系统的输出，反馈给ESO，u是ADRC的输出控制量{	float u0;	float e=0;	float e1=0;	float e2=0;//**********   TD  ************	td_x1=td_x1+h*td_x2;                        //td_x1=v1;	td_x2=td_x2+h*fst(td_x1,td_x2,v);           //td_x2=v2;//********  eso  *************	e=z1-y;	z1=z1+h*(z2-beta01*e);	z2=z2+h*(z3-beta02*fal(e,0.5,delta)+b*u);	z3=z3-h*beta03*fal(e,0.25,delta);//***********  NLSEF *************	e1=td_x1-z1;   				//e1=v1-z1;   	e2=td_x2-z2;				//e2=v2-z2;//    e1=v-z1;//	e2=-z2;	u0=beta1*fal(e1,alpha1,delta)+beta2*fal(e2,alpha2,delta);	if(u0<-10.0) u0=-10.0;	if(u0>10.0)  u0=10.0;		return(u0);                 //u=u0-z3/b;}float fst(float x1,float x2,float v){	float td_y=0;	float a0=0;	float a=0;	float fhan=0;	float d=0;	float d0=0;	//float flag_y=0;	//float flag_a=0;		d=r*h;	d0=h*d;	td_y=x1-v+h*x2;	a0=sqrt(d*d+8*r*fabs(td_y));	//if(td_y>0) flag_y=1;           //sign(td_y);	//else 	   flag_y=-1;		if(fabs(td_y)>d0)		a=x2+0.5*(a0-d)*sign(td_y);	else		a=x2+td_y/h;			//if(a>0) flag_a=1;	//else 	flag_a=-1;		if (fabs(a)>d)		fhan=-r*sign(a);	else		fhan=-r*a/d;	return(fhan);}float fal(float e,float alfa,float delta){	//float flag_e=0.0;	float y=0.0;	//if(e>0) flag_e=1.0;	//if(e<0) flag_e=-1.0;	//if(e==0) flag_e=0.0;	if(fabs(e)>delta) 		y=pow(fabs(e),alfa)*sign(e);	else			  		y=e/pow(delta,1.0-alfa);	return(y);	}float sign(float x){  if(x>0)      return(1);  if(x<0)      reture(-1);}	  
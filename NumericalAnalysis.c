#include <stdio.h>
#include <math.h>
#include <time.h>
#define e 2.71828182846
#define pi 3.14159265359
#define MAX 15
#define VAR 200
typedef struct func{
	double derece;
	int tur, base;
	double fonkDerece;
	double katsayi, fonkKatsayi;
	}function;
// Methods
void bisection();
void regulaFalsi();
void newton();
void tersMatris();
void gaussEliminasyon();
void gaussSeidal();
void sayisalTurev();
void simpson();
void trapez();
void enterpolasyon();
//KFunctions
void fonkOku(function polinom[], int n);
void fonkYaz(function fonk[], int n);
double polyHesap(double x, function fonk[], int n);
double polyTurevHesap(double x, function fonk[], int n);
void matrisInput(double matris[][MAX], int n);
void matrisPrint(double matris[][MAX], int n);
void matrisElemanSwap(double matris[][MAX], double sonucmatrisi[], int max[], int n);

int main(){
	srand(time(NULL));
	int i, a=1;
	while(a==1){
		system("cls");
		printf("Pleae enter name of the method\n\n");
		printf("1. Bisection\n2. Regula-Falsi\n3. Newton-Raphson\n4. NxN'lik inverse\n5. Gauss Elimination\n6. Gauss Seidal\n7. Numerical Derivative\n8. Simpson\n9. Trapez\n10. Variable non-Transformed Gregory Newton Enterpolation ");
		do{
			scanf("%d", &a);
		}
		while(a>10 && a<1);
		switch(a){
			case 1:
				system("cls");
				bisection();
				break;
			case 2:
				system("cls");
				regulaFalsi();
				break;
			case 3:
				system("cls");
				newton();
				break;
			case 4:
				system("cls");
				tersMatris();
				break;
			case 5:
				system("cls");
				gaussEliminasyon();
				break;
			case 6:
				system("cls");
				gaussSeidal();
				break;
			case 7:
				system("cls");
				sayisalTurev();
				break;
			case 8:
				system("cls");
				simpson();
				break;
			case 9:
				system("cls");
				trapez();
				break;
			case 10:
				system("cls");
				enterpolasyon();
				break;
		}
		printf("\n\nAna Ekrana Donmek Icin 1'i\nProgrami Kapatmak Icin 0'i Tuslayiniz..\n");
		do{
			scanf("%d", &a);
		}
		while(a>1 && a<0);
	}
	return 0;
}
void newton(){
	double vars[VAR], c, tmp, gecici, a1, b1;
	double tolerans, araDeger, maxit;
	int n, i=-1;
	function polinom[MAX];
	
	do{
		printf("Newton-Raphson\n");
		printf("Kac Eleman Olacagini Giriniz.. (MAX 15)");
		scanf("%d", &n);
		fonkOku(polinom, n);
		system ("cls");
		fonkYaz(polinom, n);		
		printf("\nDevam etmek icin 1'e, tekrar fonksiyon yazmak icin 0'a basiniz.");
		gecici = getch();
	}while(gecici=='0');
	system ("cls");
	fonkYaz(polinom, n);
	printf("baslangic degerini giriniz: ");
	scanf("%lf", &vars[0]);
	printf("Tolerans'i Giriniz: ");
	scanf("%lf", &tolerans);
	printf("Max Iterasyonu'u Giriniz: ");
	scanf("%lf", &maxit);
	do{
		i++;
		vars[i+1] = vars[i] - (polyHesap(vars[i], polinom, n))/(polyTurevHesap(vars[i], polinom, n));
		printf("%d. Iterasyon:\nxn: %g f(xn): %g\nf'(xn): %g\nxn+1: %g\n\n", i+1, vars[i], polyHesap(vars[i], polinom, n), polyTurevHesap(vars[i], polinom, n), vars[i+1]);
	}while(vars[i+1]-vars[i] >= tolerans && maxit > i);
	printf("\nadim sayisi: %d\nkokunuz: %lf", i, vars[i+1]);
}
void bisection(){
	double a, b, c, tmp, gecici;
	double tolerans, araDeger, maxit;
	int counter=0, n;
	function polinom[MAX];
	do{
		system ("cls");
		printf("Bisection\n");
		printf("Kac Eleman Olacagini Giriniz.. (MAX 15)");
		scanf("%d", &n);
		fonkOku(polinom, n);
		system ("cls");
		fonkYaz(polinom, n);		
		printf("\nDevam etmek icin 1'e, tekrar fonksiyon yazmak icin 0'a basiniz.");
		gecici = getch();
	}while(gecici=='0');
	system ("cls");
	fonkYaz(polinom, n);
	printf("icerisinde kok bulunan a ve b araliklarini giriniz: (a b)");
	scanf("%lf %lf", &a, &b);
	printf("Tolerans'i Giriniz: ");
	scanf("%lf", &tolerans);
	printf("Max Iterasyonu'u Giriniz: ");
	scanf("%lf", &maxit);
	do{
		counter++;
		c = (a+b)/2;
		araDeger = fabs((double)(a-b)/pow(2, counter));
		printf("%d. Iterasyon:\na: %g f(a): %g\nb: %g f(b): %g\nc: %g f(c): %g\n\n", counter, a, polyHesap(a, polinom, n), b, polyHesap(b, polinom, n), c, polyHesap(c, polinom, n));
		if(polyHesap(a, polinom, n)*polyHesap(c, polinom, n) < 0){
			b = c;
		}
		else a = c;
	}while(araDeger>tolerans && maxit > counter);
	printf("\nadim sayisi: %d\nkokunuz: %lf", counter, c);
}
void regulaFalsi(){
	double a, b, c, tmp, gecici, a1, b1;
	double tolerans, araDeger, maxit;
	int counter=0, n;
	function polinom[MAX];
	do{
		system ("cls");
		printf("Regula-Falsi\n");
		printf("Kac Eleman Olacagini Giriniz.. (MAX 15)");
		scanf("%d", &n);
		fonkOku(polinom, n);
		system ("cls");
		fonkYaz(polinom, n);		
		printf("\nDevam etmek icin 1'e, tekrar fonksiyon yazmak icin 0'a basiniz.");
		gecici = getch();
	}while(gecici=='0');
	system ("cls");
	fonkYaz(polinom, n);
	printf("icerisinde kok bulunan a ve b araliklarini giriniz: (a b)");
	scanf("%lf %lf", &a, &b);
	printf("Tolerans'i Giriniz: ");
	scanf("%lf", &tolerans);
	printf("Max Iterasyonu'u Giriniz: ");
	scanf("%lf", &maxit);
	do{
		counter++;
		a1 = polyHesap(a, polinom, n);
		b1 = polyHesap(b, polinom, n);
		c = (b*a1-a*b1)/(a1-b1);
		araDeger = (fabs(a-b))/pow(2, counter);
		printf("%d. Iterasyon:\na: %g f(a): %g\nb: %g f(b): %g\nc: %g f(c): %g\n\n", counter, a, a1, b, b1, c, polyHesap(c, polinom, n));
		if(a1*polyHesap(c, polinom, n) < 0){
			b = c;
		}
		else a = c;
	}while(araDeger >= tolerans && maxit > counter);
	printf("\nadim sayisi: %d\nkokunuz: %lf", counter, c);
}
void tersMatris(){
	int i, j, n;
	int x=0;
	double matris[MAX][MAX], birimmatris[MAX][MAX]={{0},{0}}, d = 1;
	int flag=0;
	printf("Matris Tersi\n");
	printf("Lutfen n Katsayisini Giriniz...\n");
	scanf("%d", &n);
	matrisInput(matris, n);
	printf("Matrisiniz:\n");
	matrisPrint(matris, n);
	
	for(i=0; i<n; i++){
		birimmatris[i][i] = 1;
	}
	while(x<n){
		// diagonalda ilerleyen (x,x) noktasý farz ettim. Önce (x,x) noktasýndaki eleman 1 olur.
		// Daha sonra altýndaki ve üstündeki sayýlar sýfýrlanýr. Ýþlemlerin aynýlarý birim matrise de uygulanýr.
		d = matris[x][x];
	//	printf("\nd= %lf\n", matris[x][x]);
		// x,x noktasýný 1 yapma
		for(j=0;j<n;j++){
				if(matris[x][j]!=0){
					matris[x][j] = matris[x][j]/d;
				}
				if(birimmatris[x][j]!=0){
					birimmatris[x][j] = birimmatris[x][j]/d;
				}
		}
		// x,x noktasýnýn altýný sýfýr yapma
		for(i=x+1;i<n;i++){
			d = matris[i][x];
			for(j=0;j<n;j++){
				matris[i][j] = matris[i][j] - d*matris[x][j];
				birimmatris[i][j] = birimmatris[i][j] - d*birimmatris[x][j];
			}
		}
		// Diagonaldaki sayý sýfýr olursa tersi alýnamaz deyip çýkar.
		for(i=0;i<n;i++){
			if(matris[i][i] == 0){
				x=n;
				flag=1;
			}
		}
		x++;
	}
	x--;
	while(x>=0 && x!=n){
		// üst üçgensel matrisi 0 yapma
		for(i=x-1; i>=0; i--){
			d = matris[i][x];
			for(j=0;j<n;j++){
				matris[i][j] = matris[i][j] - d*matris[x][j];
				birimmatris[i][j] = birimmatris[i][j] - d*birimmatris[x][j];
			}
		}
		x--;
	}
	// Tersi alýnabilmesine göre print etme
	if(flag==1){
		printf("\nMatrisin Tersi Alinamaz..");
		sleep(2);
	}
	else{
		printf("Ters Matris: \n");
		matrisPrint(birimmatris, n);
	}
}
void gaussEliminasyon(){
	int i, j, n;
	int x=0, flag=0, counter=0;
	double variables[MAX], result=0;
	double sonucmatrisi[MAX], matris[MAX][MAX], d = 1;
	printf("Gauss Eliminasyon\n");
	printf("Lutfen n Katsayisini Giriniz...\n");
	scanf("%d", &n);
	matrisInput(matris, n);
	printf("Matrisiniz:\n");
	matrisPrint(matris, n);
	printf("Sonuc Matrisinizi Giriniz..\n");
	for(i=0; i<n; i++){
		printf("%d. eleman: ", i);
		scanf("%lf", &sonucmatrisi[i]);
	}
	while(x<n){
		// diagonalda ilerleyen (x,x) noktasý farz ettim. Önce (x,x) noktasýndaki eleman 1 olur.
		// Daha sonra altýndaki ve üstündeki sayýlar sýfýrlanýr. Ýþlemlerin aynýlarý birim matrise de uygulanýr.
		d = matris[x][x];
		// x,x noktasýný 1 yapma
		for(j=0;j<n;j++){
			if(matris[x][j]!=0){
				matris[x][j] = matris[x][j]/d;
			}
		}
		sonucmatrisi[x] = sonucmatrisi[x]/d;
		// x,x noktasýnýn altýný sýfýr yapma
		for(i=x+1;i<n;i++){
			d = matris[i][x];
			for(j=0;j<n;j++){
				matris[i][j] = matris[i][j] - d*matris[x][j];
		//		matrisPrint(matris, n);
			}
			sonucmatrisi[i] = sonucmatrisi[i] - d*sonucmatrisi[x];
		}
		// Diagonaldaki sayý sýfýr olursa tersi alýnamaz deyip çýkar.
		i=0;
		while(i<n){
			counter=0;
			for(j=0;j<n;j++){
				if(matris[i][j] == 0){
				counter++;
				}
			}
			if(counter == 3 && sonucmatrisi[i] != 0){
				x=n;
				i=0;
				flag=1;
			}
			i++;
		}
		x++;
	}
	matrisPrint(matris, n);
	printf("Sonuc Matrisi: ");
	for(i=0;i<n;i++){
		printf("%lf   ", sonucmatrisi[i]);
	}
	if(flag==0){
		for(i=0;i<n;i++){
			result=0;
			for(j=0;j<i;j++){
				result = result + matris[n-i-1][n-j-1]*variables[j];
			}
			variables[i] = sonucmatrisi[n-i-1] - result;
		}
		printf("\n");
		for(i=0;i<n;i++){
			printf("%d. Degisken: %lf\n", i+1, variables[n-i-1]);
		}	
	}
	else{
		printf("Matris Cozumsuzdur..");
	}	
}
void gaussSeidal(){
	int i, j, n, max[2]={0};
	int counter=0, it=0, flag=0;
	double diagonal[MAX][2], hatapayi, variables[MAX], diff=1, maxit;
	double sonucmatrisi[MAX], matris[MAX][MAX], sonuc1, sonuc2, sonuc;
	printf("Gauss Seidal\n");
	printf("Lutfen n Katsayisini Giriniz...\n");
	scanf("%d", &n);
	matrisInput(matris, n);
	printf("Matrisiniz:\n");
	matrisPrint(matris, n);
	printf("Sonuc Matrisinizi Giriniz..\n");
	for(i=0; i<n; i++){
		printf("%d. eleman: ", i);
		scanf("%lf", &sonucmatrisi[i]);
		variables[i] = 1;
	}
	printf("Hata Payi Giriniz..");
	scanf("%lf", &hatapayi);
	printf("Max Iterasyonu'u Giriniz: ");
	scanf("%lf", &maxit);
	for(i=0;i<n;i++){
		sonuc1=1;
		sonuc2=1;
		// saurrus yönteminde yaptýðýmýza benzer olarak matrisin altýna ayný matrisi ekleyip
		// çapraz bir þekilde çarparsak (soldan saða ve saðdan sola) bütün diagonal çarpýmlarýný bulmuþ oluruz.
		for(j=0;j<n;j++){
			sonuc1 = sonuc1*matris[(j+i)%n][j];
			sonuc2 = sonuc2*matris[(j+i)%n][n-j-1];
		}
	//	printf("i:%d, sonuc1: %g, sonuc2: %g\n", i, sonuc1, sonuc2);
		diagonal[i][0] = sonuc1;
		diagonal[i][1] = sonuc2;
	}
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			// 6 ihtimalden hangisinin en büyük olduðunu bulmak için
			if(fabs(diagonal[i][j]) > fabs(diagonal[max[0]][max[1]])){
				max[0] = i;
				max[1] = j;
			}
		}
	}
	// 2i+j. ihtimal'de en yüksek deðere ulaþýlmýþ olur.
	// printf("\n%d. ihtimal\n", 2*max[0]+max[1]+1);
	matrisElemanSwap(matris, sonucmatrisi, max, n);
	matrisPrint(matris, n);
	it++;
	printf("\n%d    ", it);
	for(i=0;i<n;i++){
		printf(" %g     ", variables[i]);
	}
	while(flag==0 && it<maxit){
		counter=0;
		it++;
		printf("\n%d    ", it);
		for(i=0;i<n;i++){
			sonuc=sonucmatrisi[i];
			for(j=0;j<n;j++){
				if(i!=j){
					sonuc -= matris[i][j]*variables[j];
				}
			}
			diff = fabs(sonuc/matris[i][i] - variables[i]);
			printf(" %lf  %lf     ", variables[i], diff);
			variables[i] = sonuc/matris[i][i];
			if(diff<hatapayi){
				counter++;
			}
		}
		printf("\n");
		if(counter==n){
			flag=1;
		}
	}
	
}
void sayisalTurev(){
	double tmp, gecici;
	double x, h, sonuc=0, sonuc1, sonuc2;
	int n, i;
	function polinom[MAX];	
	do{
		system ("cls");
		printf("Sayisal Turev\n");
		printf("Kac Eleman Olacagini Giriniz.. (MAX 15)");
		scanf("%d", &n);
		fonkOku(polinom, n);
		system ("cls");
		fonkYaz(polinom, n);		
		printf("\nDevam etmek icin 1'e, tekrar fonksiyon yazmak icin 0'a basiniz.\n");
		gecici = getch();
	}while(gecici=='0');
	system ("cls");
	fonkYaz(polinom, n);
	printf("\nx Degerini Giriniz: ");
	scanf("%lf", &x);
	printf("Tolerans'i Giriniz: ");
	scanf("%lf", &h);
	printf("1-)Geri Fark\n2-)Ileri Fark\n3-)Merkezi Fark\n4-)Butun Yontemleri Goster..\n");
	scanf("%d", &i);
	switch (i){
		case 1:
			sonuc1 = polyHesap(x, polinom, n);
			sonuc2 = polyHesap(x-h, polinom, n);
			sonuc = (sonuc1-sonuc2)/h;
			printf("Geri Fark: %lf", sonuc);
			break;
		case 2:
			sonuc1 = polyHesap(x+h, polinom, n);
			sonuc2 = polyHesap(x, polinom, n);
			sonuc = (sonuc1-sonuc2)/h;
			printf("Ileri Fark: %lf", sonuc);
			break;
		case 3:
			sonuc1 = polyHesap(x+h, polinom, n);
			sonuc2 = polyHesap(x-h, polinom, n);
			sonuc = (sonuc1-sonuc2)/(2*h);
			printf("Merkezi Fark: %lf", sonuc);
			break;
		case 4:
			sonuc1 = polyHesap(x, polinom, n);
			sonuc2 = polyHesap(x-h, polinom, n);
			sonuc = (sonuc1-sonuc2)/h;
			printf("Geri Fark: %lf\n", sonuc);
			sonuc1 = polyHesap(x+h, polinom, n);
			sonuc2 = polyHesap(x, polinom, n);
			sonuc = (sonuc1-sonuc2)/h;
			printf("Ileri Fark: %lf\n", sonuc);
			sonuc1 = polyHesap(x+h, polinom, n);
			sonuc2 = polyHesap(x-h, polinom, n);
			sonuc = (sonuc1-sonuc2)/(2*h);
			printf("Merkezi Fark: %lf", sonuc);
			break;
	}
}
void simpson(){
	double tmp, gecici, h, a, b, sonuc=0, sonuc1=0, ilk, son;
	int n, i, parca, sayac=0;
	char j;
	function polinom[MAX];
	do{
		system ("cls");
		printf("Simpson 1/3 ve 3/8\n");
		printf("Kac Eleman Olacagini Giriniz.. (MAX 15)");
		scanf("%d", &n);
		fonkOku(polinom, n);
		system ("cls");
		fonkYaz(polinom, n);		
		printf("\nDevam etmek icin 1'e, tekrar fonksiyon yazmak icin 0'a basiniz.\n");
		gecici = getch();
	}while(gecici=='0');
	system ("cls");
	fonkYaz(polinom, n);
	printf("Lutfen Alt ve Ust Sinirlari Giriniz.. (a b)");
	scanf("%lf %lf", &a, &b);
	do{
		printf("Lutfen Kac Parcaya Ayrilacagini Giriniz.. (Cift Sayi Giriniz)");
		scanf("%d", &parca);
	}
	while(parca%2!=0);
	h = (b-a)/parca;
	do{
		system("cls");
		fonkYaz(polinom, n);
		printf("1-) 1/3 Yontemi\n2-) 3/8 Yontemi\n3-) Her Ikisini de Goster  ");
		j = getch();
	}
	while(j!='1' && j!='2' && j!='3');
	switch (j){
		case '1':
			sonuc = polyHesap(a, polinom, n);
			sonuc += polyHesap(b, polinom, n);
			for(i=1;i<parca;i++){
				if(i%2==1){
					sonuc += 4*polyHesap(a+h*i, polinom, n);
				}
				else if(i%2==0){
					sonuc += 2*polyHesap(a+h*(i), polinom, n);
				}
			}
			sonuc = h*sonuc/3;
			printf("\nSimpson 1/3 Ile Elde Edilen Sonuc: %lf", sonuc);
			break;
		case '2':
			sonuc = 0;
			while(sayac<parca){
				ilk = a+h*sayac;
				son = ilk+h;
				sonuc += 1*polyHesap(ilk, polinom, n);
				sonuc += 3*polyHesap(ilk+h/3, polinom, n);
				sonuc += 3*polyHesap(ilk+2*h/3, polinom, n);
				sonuc += 1*polyHesap(son, polinom, n);
				sayac++;
			}
			sonuc *= h/8;
			printf("\nSimpson 3/8 Ile Elde Edilen Sonuc: %lf", sonuc);
			break;
		case '3':
			sonuc = polyHesap(a, polinom, n);
			sonuc += polyHesap(b, polinom, n);
			for(i=1;i<parca;i++){
				if(i%2==1){
					sonuc += 4*polyHesap(a+h*i, polinom, n);
				}
				else if(i%2==0){
					sonuc += 2*polyHesap(a+h*(i), polinom, n);
				}
			}
			sonuc = h*sonuc/3;
			printf("\nSimpson 1/3 Ile Elde Edilen Sonuc: %lf", sonuc);
			sonuc = 0;
			while(sayac<parca){
				ilk = a+h*sayac;
				son = ilk+h;
				sonuc += 1*polyHesap(ilk, polinom, n);
				sonuc += 3*polyHesap(ilk+h/3, polinom, n);
				sonuc += 3*polyHesap(ilk+2*h/3, polinom, n);
				sonuc += 1*polyHesap(son, polinom, n);
				sayac++;
			}
			sonuc *= h/8;
			printf("\nSimpson 3/8 Ile Elde Edilen Sonuc: %lf", sonuc);
			break;
	}
}
void trapez(){
	double tmp, gecici, h, a, b, sonuc=0;
	int n, i, parca, j, sayac=0;
	function polinom[MAX];
	do{
		system ("cls");
		printf("Trapez\n");
		printf("Kac Eleman Olacagini Giriniz.. (MAX 15)");
		scanf("%d", &n);
		fonkOku(polinom, n);
		system ("cls");
		fonkYaz(polinom, n);		
		printf("\nDevam etmek icin 1'e, tekrar fonksiyon yazmak icin 0'a basiniz.\n");
		gecici = getch();
	}while(gecici=='0');
	system ("cls");
	fonkYaz(polinom, n);
	printf("Lutfen Alt ve Ust Sinirlari Giriniz.. (a b)");
	scanf("%lf %lf", &a, &b);
	do{
		printf("Lutfen Kac Parcaya Ayrilacagini Giriniz.. (Cift Sayi Giriniz)");
		scanf("%d", &parca);
	}
	while(parca%2!=0);
	h = (b-a)/parca;
	sonuc += polyHesap(a, polinom, n)/2;
	sonuc += polyHesap(b, polinom, n)/2;
	for(i=1;i<n;i++){
		sonuc += polyHesap(a+h*i, polinom, n);
	}
	sonuc *= h;
	printf("Trapez Yontemi Ile Elde Edilen Sonuc: %lf", sonuc);
}
void enterpolasyon(){
	int i, j, n, k;
	double degerler[MAX][10] = {0}, diff=1, sonuc=0;
	double deger, l, x0, h, kats, tmp;
	function polinom[MAX];
	printf("Degisken Donusumsuz Gregory Newton Enterpolasyon\n");
	printf("x0 Degerini Giriniz: ");
	scanf("%lf", &x0);
	printf("h Degerini Giriniz: ");
	scanf("%lf", &h);
	printf("Kac Adet Deger Gireceginizi Yaziniz: ");
	scanf("%d", &n);
	for(i=0;i<n;i++){
		l = x0+h*i;
		printf("F(%g): ", l);
		scanf("%lf", &degerler[i][0]);
	}
	j=1;
	tmp = n;
	while(diff!=0 && tmp!=0){
		for(i=0;i<tmp-1;i++){
			degerler[i][j] = degerler[i+1][j-1] - degerler[i][j-1];
		}
		diff = degerler[1][j] - degerler[0][j];
		j++;
		tmp--;
	}
	printf("%d\n", j);
	for(i=0;i<n;i++){
		for(k=0;k<j;k++){
			printf("%g\t", degerler[i][k]);
		}
		printf("\n");
	}
	printf("Sonucunu Bulmak Istediginiz x Degerini Giriniz: ");
	scanf("%lf", &deger);
	kats = (deger-x0)/h;
	sonuc = degerler[0][0];
	sonuc += kats*degerler[0][1];
	for(i=2;i<j;i++){
		tmp=1;
		for(k=0;k<i;k++){
			tmp*=(kats-k)/(k+1);
		}
		sonuc += tmp*degerler[0][i];
	}
	printf("\nf(%lf): %lf", deger, sonuc);
}
void fonkOku(function fonk[], int n){
	int i;
	for(i=0;i<n;i++){
		system ("cls");
		printf("%d. Elemanin Turu:\n1-) Polinom\n2-) Ustel\n3-) Logaritmik\n", i+1);
		scanf("%d", &fonk[i].tur);
		switch(fonk[i].tur){
			case 1:
				printf("a.x^b = ");
				scanf("%lf %lf", &fonk[i].katsayi, &fonk[i].derece);
				break;
			case 2:
				printf("'base' Ifadesi icin e: 0\nA.[(base)^(b.x^c)]^D = ");
				scanf("%lf %d %lf %lf %lf", &fonk[i].fonkKatsayi, &fonk[i].base, &fonk[i].katsayi, &fonk[i].derece, &fonk[i].fonkDerece);
				break;
			case 3:
				printf("'base' Ifadesi icin e: 0\nA.[log(base)(b.x^c)]^D = ");
				scanf("%lf %d %lf %lf %lf", &fonk[i].fonkKatsayi, &fonk[i].base, &fonk[i].katsayi, &fonk[i].derece, &fonk[i].fonkDerece);
				break;
		}
	}
}
void fonkYaz(function fonk[], int n){
	int i;
	for(i=0;i<n;i++){	
		switch(fonk[i].tur){
			case 1:
				if(i==n-1){
					if(fonk[i].katsayi == 1 && fonk[i].derece == 1){
						printf("x");
					}
					else if(fonk[i].katsayi == 1 && fonk[i].derece!=0){
						printf("x^%g", fonk[i].derece);
					}
					else if(fonk[i].derece==0){
						printf("%g", fonk[i].katsayi);
					}
					else if(fonk[i].katsayi==-1){
						printf("-x^%g", fonk[i].derece);
					}
					else printf("%gx^%g", fonk[i].katsayi, fonk[i].derece);
				}
				else{
					if(fonk[i].katsayi == 1 && fonk[i].derece == 1){
						printf("x + ");
					}
					else if(fonk[i].katsayi == 1 && fonk[i].derece!=0){
						printf("x^%g + ", fonk[i].derece);
					}
					else if(fonk[i].derece==0){
						printf("%g + ", fonk[i].katsayi);
					}
					else if(fonk[i].katsayi==-1){
						printf("-x^%g + ", fonk[i].derece);
					}
					else printf("%gx^%g + ", fonk[i].katsayi, fonk[i].derece);
				}
				break;
			case 2:
				if(i==n-1){
					if(fonk[i].base == 0){
						printf("%g.[e^(%g.x^%g)]^%g", fonk[i].fonkKatsayi, fonk[i].katsayi, fonk[i].derece, fonk[i].fonkDerece);
					}
					else printf("%g.[%d^(%g.x^%g)]^%g", fonk[i].fonkKatsayi, fonk[i].base, fonk[i].katsayi, fonk[i].derece, fonk[i].fonkDerece);
				}
				else{
					if(fonk[i].base == 0){
						printf("%g.[e^(%gx^%g)]^%g + ", fonk[i].fonkKatsayi, fonk[i].katsayi, fonk[i].derece, fonk[i].fonkDerece);
					}
					else printf("%g.[%d^(%g.x^%g)]^%g + ", fonk[i].fonkKatsayi, fonk[i].base, fonk[i].katsayi, fonk[i].derece, fonk[i].fonkDerece);
				}
				break;
			case 3:
				if(i==n-1){
					if(fonk[i].base == 0){
						printf("%g.[ln(%gx^%g)]^%g", fonk[i].fonkKatsayi, fonk[i].katsayi, fonk[i].derece, fonk[i].fonkDerece);
					}
					else printf("%g.[log(%d)(%gx^%g)]^%g", fonk[i].fonkKatsayi, fonk[i].base, fonk[i].katsayi, fonk[i].derece, fonk[i].fonkDerece);
				}
				else{
					if(fonk[i].base == 0){
						printf("%g.[ln(%gx^%g)]^%g + ", fonk[i].fonkKatsayi, fonk[i].katsayi, fonk[i].derece, fonk[i].fonkDerece);
					}
					else printf("%g.[log(%d)(%gx^%g)]^%g + ", fonk[i].fonkKatsayi, fonk[i].base, fonk[i].katsayi, fonk[i].derece, fonk[i].fonkDerece);
				}
				break;
		}
	}
	printf("\n");
}
double polyHesap(double x, function fonk[], int n){
	int i;
	double sonuc, tmp;
	sonuc = 0;
	for(i=0;i<n;i++){
		if(fonk[i].tur == 1){
			sonuc += fonk[i].katsayi*pow(x, fonk[i].derece);
		}
		else if(fonk[i].tur == 2){
			if(fonk[i].base == 0){
				tmp = pow(e, fonk[i].katsayi*pow(x, fonk[i].derece));
				sonuc += pow(tmp, fonk[i].fonkDerece)*fonk[i].fonkKatsayi;
			}
			else{
				tmp = fonk[i].katsayi*pow(x, fonk[i].derece);
				tmp = pow((double)fonk[i].base, tmp);
				sonuc += pow(tmp, fonk[i].fonkDerece)*fonk[i].fonkKatsayi;

			}
		}
		else if(fonk[i].tur == 3){
			if(fonk[i].base == 0){
				tmp = log(pow(x, fonk[i].derece));
				sonuc += pow(tmp, fonk[i].fonkDerece)*fonk[i].fonkKatsayi;
			}
			else{
				tmp = log10(fonk[i].katsayi*pow(x, fonk[i].derece))/log10((double)fonk[i].base);
				sonuc += pow(tmp, fonk[i].fonkDerece)*fonk[i].fonkKatsayi;
			}
		}
	}
	return sonuc;
}
double polyTurevHesap(double x, function fonk[], int n){
	int i, j;
	double sonuc, tmp = x;
	sonuc = 0;
	for(i=0;i<n;i++){
		switch(fonk[i].tur){
			case 1:
				// if else kullanilmayabilirdi ancak uzeri 0 olan degerleri almayacagi kesinlestirilmis oldu
				if(fonk[i].derece == 1){
					sonuc += fonk[i].katsayi;
				}
				else if(fonk[i].derece > 1){
					sonuc += fonk[i].katsayi*fonk[i].derece*pow(x, fonk[i].derece-1);
			 	}
				break;
			case 2:
				if(fonk[i].base == 0){
					tmp = pow(e, pow(x, fonk[i].derece));
					sonuc += fonk[i].fonkKatsayi*fonk[i].fonkDerece*pow(tmp,fonk[i].fonkDerece-1)*tmp*fonk[i].katsayi*fonk[i].derece*pow(x, fonk[i].derece-1);
				}
				else{
					tmp = pow(fonk[i].base, pow(x, fonk[i].derece));
					sonuc += fonk[i].fonkKatsayi*fonk[i].fonkDerece*pow(tmp,fonk[i].fonkDerece-1)*tmp*log((double)fonk[i].base)*fonk[i].katsayi*fonk[i].derece*pow(x, fonk[i].derece-1);
				}
				break;
			case 3:
				if(fonk[i].base == 0){
					tmp = log(pow(x, fonk[i].derece));
					sonuc += pow(tmp, fonk[i].fonkDerece)*fonk[i].fonkKatsayi;
				}
				else{
					tmp = log10(pow(x, fonk[i].derece))/log10((double)fonk[i].base);
					sonuc += fonk[i].fonkKatsayi*fonk[i].fonkDerece*pow(tmp,fonk[i].fonkDerece-1)*fonk[i].katsayi*fonk[i].derece*pow(x, fonk[i].derece-1)/fonk[i].katsayi*pow(x, fonk[i].derece)/log((double)fonk[i].base);
				}
				break;
		}
	}
	return sonuc;
}
void matrisInput(double matris[][MAX], int n){
	int i, j, choose;
	system("cls");
	printf("1-) Kendim Doldurmak Istiyorum.\n2-) Rastgele Elemanlarla Doldur. (-25 - +25)\n");
	scanf("%d", &choose);
	if(choose==2){
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				matris[i][j] = rand()%25*pow(-1,rand());
			}
		}
	}
	else if(choose==1){
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				printf("%d satir %d sutun: ",i,j);
				scanf("%lf", &matris[i][j]);
			}
		}
	}
	else{
		printf("\nInput Hatasi, Lutfen 2 saniye sonra tekrar deneyiniz..");
		sleep(2);
		matrisInput(matris, n);
	}
}
void matrisPrint(double matris[][MAX], int n){
	int i, j;
	printf("\n");
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			printf("%lf\t", matris[i][j]);
		}
		printf("\n\n");
	}
}
void matrisElemanSwap(double matris[][MAX], double sonucmatrisi[], int max[], int n){
	int i, j;
	double yenimatris[MAX][MAX], yenisonuc[MAX];
	if(max[1] == 0){
		for(i=0;i<n-1;i++){
			for(j=0;j<n;j++){
				yenimatris[i][j] = matris[(max[0]+i)%n][j];
			}
			yenisonuc[i] = sonucmatrisi[(max[0]+i)%n];
		}	
	}
	else{
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				yenimatris[n-i-1][j] = matris[(max[0]+i)%n][j];
			}
			yenisonuc[n-i-1] = sonucmatrisi[(max[0]+i)%n];
		}
	}
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			matris[i][j] = yenimatris[i][j];
		}
		sonucmatrisi[i] = yenisonuc[i];
	}
}

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


//Criado por Allan Cruvinel

struct data{
    int qtatual;
    int qtmin;
    char datval[11];
    char desc[40];
    ;
    };

int nreg;
FILE *p;


void remover(struct data *registro);
void altera(struct data *registro);
void movqtdade(struct data *registro);
void pesquisavalidade(struct data *registro);
void naodispo(struct data *registro);
void pesquisaletra(struct data *registro);
int comparachar(char *a, char *b);
void lerregatual();
void add1total();
void inserir(struct data *registro);
void listartodos(struct data *registro);


main()
{

    struct data registro;
    struct data *p;
    p = &registro;
    setlocale(LC_ALL, "Portuguese");
    lerregatual();
    int option = -1;
    printf("Criado por Allan Cruvinel____________________\nBem vindo ao Sistema de Gerenciamento de produtos!!!\n");
    printf("escolha a opção desejada\n\n");


    while(option !=10)
    {
        printf("\n1 - entra produto.\n2 - lista produtos na tela.\n3 - pesquisa um produto pela descrição.\n4 - pesquisa um produto pela 1° letra da descrição.\n5 – pesquisar uma determinada data de validade.\n6 - pesquisa os produtos não disponíveis.\n7 - movimenta quantidade em estoque(entrada e saída).\n8 - altera produto.\n9 - exclui produto.\n10 - sair.\n");
        scanf("%d",&option);
        switch (option)
        {
            case 1:
            {
                inserir(p);

                break;
            }
            case 2:
            {
                listartodos(p);
                break;
            }
            case 3:
            {
                pesquisa(p);
                break;
            }
            case 4:
            {
                //
                pesquisaletra(p);
                break;
            }
            case 5:
            {
                pesquisavalidade(p);
                break;
            }
            case 6:
            {
                naodispo(p);
                break;
            }
            case 7:
            {
                movqtdade(p);
                break;
            }
            case 8:
            {
                altera(p);
                break;
            }
            case 9:
            {
                remover(p);
                break;
            }
            case 10:
            {
                printf("Até mais!\n");
                system("pause");
                exit(0);
                break;
            }
            default:
            {
                printf("Opcao invalida");
                break;
            }
        }
    }
}


void remover(struct data *registro)
{
    if(nreg==0)
    {
        printf("Nao ha registros para remover");

    }
    else
    {




    char encontrar[40],*ppesquisa,*refer;
    int k;
    int encontrado=0;

    p = fopen("produtos.txt","r+");

    printf("Escreva a descrição para Encontrar\n");
    gets(encontrar);
    gets(encontrar);
    ppesquisa = encontrar;
    for(int i=0;i<nreg;i++)
    {
    k = i*sizeof(*registro);
    fseek(p,k,0);
    //printf("k = %d\n",k);


	printf("\n");
    fread(&*registro,sizeof(*registro),1,p);


    refer = &registro->desc;

    if(comparachar(ppesquisa,refer) == 1)
    {
            *registro->desc=5;
           *registro->datval=0;
           registro->qtatual=0;
           registro->qtmin=0;
           fseek(p,i*sizeof(*registro),0);

           fwrite(&*registro,sizeof(*registro),1,p);
           //printf("\nDados Removidos");
            printf("dados removidos \n");
            encontrado=1;

    }
    }

    if(encontrado==0)
    {
        printf("dados não encontrado \n");
    }

    fclose(p);
    }



}


void altera(struct data *registro)
{
    lerregatual();
    if(nreg==0)
    {
        printf("Nao ha registros para alterar");
    }
    else
    {
    char encontrar[40],*ppesquisa,*refer;
    int k;
    int encontrado=0;

    p = fopen("produtos.txt","r+");

    printf("Escreva a descrição para Encontrar\n");
    gets(encontrar);
    gets(encontrar);
    ppesquisa = encontrar;
    for(int i=0;i<nreg;i++)
    {
    k = i*sizeof(*registro);
    fseek(p,k,0);
    //printf("k = %d\n",k);


	printf("\n");
    fread(&*registro,sizeof(*registro),1,p);


    refer = &registro->desc;

    if(comparachar(ppesquisa,refer) == 1)
    {
            int escolha;
            int alteracao;

            printf("Informacoes do registro escolhido\n\ndescricao: %s\n",registro->desc);
            printf("quantidade atual %d\n",registro->qtatual);
            printf("quantidade minima %d\n",registro->qtmin);
            printf("data de validade %s\n",registro->datval);
            fseek(p,i*sizeof(*registro),0);


            escolha=0;

                printf("\nqual registro deseja alterar?\n0 - descrição do produto\n1 - Quantidade atual\n2 - Quantidade minima\n3 - Data de Validade\n4 - Todas as opções\n5 - Sair de alteração\n");
                scanf("%d",&escolha);

            switch(escolha)
            {
            case 0:
                {
                    printf("escreva a nova descrição atual ");
                    gets(registro->desc);
                    gets(registro->desc);
                    fseek(p,i*sizeof(*registro),0);
                    fwrite(&*registro,sizeof(*registro),1,p);
                    break;
                }
            case 1:
                {
                    printf("escreva a nova quantidade atual ");
                    scanf("%d",&alteracao);
                    registro->qtatual=alteracao;
                    fseek(p,i*sizeof(*registro),0);
                    fwrite(&*registro,sizeof(*registro),1,p);
                    break;
                }
            case 2:
                {
                    printf("escreva a nova quantidade minima ");
                    scanf("%d",&alteracao);
                    registro->qtmin=alteracao;
                    fseek(p,i*sizeof(*registro),0);
                    fwrite(&*registro,sizeof(*registro),1,p);
                    break;
                }
            case 3:
                {
                    printf("escreva a nova data de validade no formado DD/MM/AAAA ");
                    gets(registro->datval);
                    gets(registro->datval);
                    fseek(p,i*sizeof(*registro),0);
                    fwrite(&*registro,sizeof(*registro),1,p);
                    break;
                }
            case 4:
                {
                    printf("escreva a nova descrição atual ");
                    gets(registro->desc);
                    gets(registro->desc);

                    printf("escreva a nova quantidade atual ");
                    scanf("%d",&alteracao);
                    registro->qtatual=alteracao;

                    printf("escreva a nova quantidade minima ");
                    scanf("%d",&alteracao);
                    registro->qtmin=alteracao;

                    printf("escreva a nova data de validade no formado DD/MM/AAAA ");
                    gets(registro->datval);
                    gets(registro->datval);

                    fseek(p,i*sizeof(*registro),0);
                    fwrite(&*registro,sizeof(*registro),1,p);
                    break;
                }
                case 5:
                {


                    break;
                }
            default:
                {
                    printf("tecla incorreta, saindo de alteração......");
                    break;
                }
            }

        encontrado=1;
    }
    }

    if(encontrado==0)
    {
        printf("nome nao encontrado no registro \n");
    }
    }




    fclose(p);
    }






void movqtdade(struct data *registro)
{
    lerregatual();
    if(nreg==0)
    {
        printf("Nao ha registros para movimentar estoque");
    }
    else
    {











    char encontrar[40],*ppesquisa,*refer;
    int k;
    int encontrado=0;

    p = fopen("produtos.txt","r+");

    printf("Escreva a descrição para Encontrar\n");
    gets(encontrar);
    gets(encontrar);
    ppesquisa = encontrar;
    for(int i=0;i<nreg;i++)
    {
    k = i*sizeof(*registro);
    fseek(p,k,0);
    //printf("k = %d\n",k);


	printf("\n");
    fread(&*registro,sizeof(*registro),1,p);


    refer = &registro->desc;

    if(comparachar(ppesquisa,refer) == 1)
    {
           int alteracao;
            fseek(p,i*sizeof(*registro),0);

            fread(&*registro,sizeof(*registro),1,p);



            printf("o a quantidade no registro é %d ",(*registro).qtatual);
            printf("escreva a movimentação com + ou - algum numero (exemplo +55, -12) ");
            scanf("%d",&alteracao);

            registro->qtatual+=alteracao;

            printf("agora a alteracao ficou %d ", (*registro).qtatual);
            getchar();

            fseek(p,i*sizeof(*registro),0);
            fwrite(&*registro,sizeof(*registro),1,p);
            //printf("dados removidos \n");
            encontrado= 1;


    }
    }

    if(encontrado==0)
    {
        printf("dado nao encontrado \n");
    }

    fclose(p);



    }


	fclose(p);
}

void pesquisavalidade(struct data *registro)
{
    lerregatual();
    if(nreg==0)
    {
        printf("Nao ha registros para checar a validade");
    }
    else
    {


    char encontrar[11],*ppesquisa,*refer;
    int k;
    int encontrado=0;

    p = fopen("produtos.txt","r");

    printf("Escreva uma data de validade para pesquisa no formado DD/MM/AAAA \n");
    gets(encontrar);
    gets(encontrar);
    ppesquisa = encontrar;
    for(int i=0;i<nreg;i++)
    {
    k = i*sizeof(*registro);
    fseek(p,k,0);
    //printf("k = %d\n",k);


	printf("\n");
    fread(&*registro,sizeof(*registro),1,p);


    refer = &registro->datval;
    //int comparou = comparachar(ppesquisa,refer);
    //printf(" %s eh igual a %s ? \n",ppesquisa,registro.nome);
    if(comparachar(ppesquisa,refer) == 1)
    {
        //printf("a palavra %s é igual a %s ",ppesquisa,refer);

        printf("validade encontrada no registro %d \n",i+1);
        //printf("registro numero %d\n\n",i+1);
        printf("descricao: %s\n",registro->desc);
        printf("quantidade atual %d\n",registro->qtatual);
        printf("quantidade minima %d\n",registro->qtmin);
        printf("data de validade %s\n",registro->datval);
        encontrado=1;
    }
    }
    fclose(p);
    if(encontrado==0)
    {
        printf("Validade nao encontrada no registro \n");
    }
    }
}

void naodispo(struct data *registro)
{
    lerregatual();
    if(nreg==0)
    {
        printf("Nao ha registros para checar a disponibilidade");
    }
    else
    {


    int min,atual;
    int k;
    int encontrado=0;

    p = fopen("produtos.txt","r");


    for(int i=0;i<nreg;i++)
    {
    k = i*sizeof(*registro);
    fseek(p,k,0);
    //printf("k = %d\n",k);


	printf("\n");
    fread(&*registro,sizeof(*registro),1,p);

    //atual = ;
    //min = ;
    //int comparou = comparachar(ppesquisa,refer);
    //printf(" %s eh igual a %s ? \n",ppesquisa,registro.nome);
    if((*registro).qtatual<(*registro).qtmin)
    {
        //printf("a palavra %s é igual a %s ",ppesquisa,refer);

        printf("baixo estoque no registro %d \n",i+1);
        //printf("registro numero %d\n\n",i+1);
        printf("descricao: %s\n",registro->desc);
        printf("quantidade atual %d\n",registro->qtatual);
        printf("quantidade minima %d\n",registro->qtmin);
        printf("data de validade %s\n",registro->datval);
        encontrado=1;
    }
    }
    fclose(p);
    if(encontrado==0)
    {
        printf("nenhum registro encontrado \n");
    }
    }
}

void pesquisaletra(struct data *registro)
{
    lerregatual();
    if(nreg==0)
    {
        printf("Nao ha registros para pesquisar pela primeira letra");
    }
    else
    {
    char encontrar,*refer;
    int k;
    int encontrado=0;
    printf("Escreva a primeira letra do produto\n");
    scanf("%c",&encontrar);
    scanf("%c",&encontrar);

    p = fopen("produtos.txt","r");

    for(int i=0;i<nreg;i++)
    {
    k = i*sizeof(*registro);
    fseek(p,k,0);
    //printf("k = %d\n",k);


	printf("\n");
    fread(&*registro,sizeof(*registro),1,p);


    refer = &registro->desc;



    if(encontrar==refer[0])
    {

        printf("Letra inicial encontrada no registro %d \n",i+1);

        printf("descricao: %s\n",registro->desc);
        printf("quantidade atual %d\n",registro->qtatual);
        printf("quantidade minima %d\n",registro->qtmin);
        printf("data de validade %s\n",registro->datval);
        encontrado=1;
    }
    }
    fclose(p);
    if(encontrado==0)
    {
        printf("nao ha registros com essa letra inicial \n");
    }
    }
}

void pesquisa(struct data *registro)
{
    lerregatual();
    if(nreg==0)
    {
        printf("Nao ha registros para pesquisar a descrição");
    }
    else
    {
    char encontrar[40],*ppesquisa,*refer;
    int k;
    int encontrado=0;

    p = fopen("produtos.txt","r");

    printf("Escreva a descrição para Encontrar\n");
    gets(encontrar);
    gets(encontrar);
    ppesquisa = encontrar;
    for(int i=0;i<nreg;i++)
    {
    k = i*sizeof(*registro);
    fseek(p,k,0);
    //printf("k = %d\n",k);


	printf("\n");
    fread(&*registro,sizeof(*registro),1,p);


    refer = &registro->desc;

    if(comparachar(ppesquisa,refer) == 1)
    {


        printf("descricão encontrada no registro %d \n",i+1);

        printf("descricao: %s\n",registro->desc);
        printf("quantidade atual %d\n",registro->qtatual);
        printf("quantidade minima %d\n",registro->qtmin);
        printf("data de validade %s\n",registro->datval);
        encontrado=1;
    }
    }
    fclose(p);
    if(encontrado==0)
    {
        printf("nome nao encontrado no registro \n");
    }
    }
}

int comparachar(char *a, char *b)
{
    int ca=0,cb=0;
    for(int i=0;a[i]!='\0';i++)
    {
        ca++;
    }
    for(int i=0;b[i]!='\0';i++)
    {
        cb++;
    }
    if(ca!=cb)
    {
        return 0;
    }
    else
    {
        for(int i=0;i<ca;i++)
        {
            if(a[i]!=b[i])
            {
                return 0;
                break;
            }
        }
        return 1;
    }

}


void listartodos(struct data *registro)
{

    lerregatual();
    if(nreg==0)
    {
        printf("Nao ha registros para listar itens");
    }
    else
    {
    int k=0;

    p = fopen("produtos.txt","r");


	if(nreg<1)
    {
        printf(" Ainda não há registros para listar");
    }
    else
    {
        for(int i=0;i<nreg;i++)
        {
        k = i*sizeof(*registro);
        fseek(p,k,0);

        printf(" \n\n");
        fread(&*registro,sizeof(*registro),1,p);

        if(registro->desc[0]!=5)
        {

        printf("registro numero %d\n\n",i+1);
        printf("descricao: %s\n",registro->desc);
        printf("quantidade atual %d\n",registro->qtatual);
        printf("quantidade minima %d\n",registro->qtmin);
        printf("data de validade %s\n",registro->datval);
        }
        }
        fclose(p);
    }

    }
}

void add1total()
{
    FILE *pn;
    pn = fopen("registros.txt","w");

	fprintf(pn,"%d ",nreg+=1);

    fclose(pn);
}

void lerregatual()
{
    FILE *pn;


    if((pn = fopen("registros.txt","r"))==NULL)
	{
	}
	fscanf(pn,"%d ",&nreg);

    fclose(pn);
}

void inserir(struct data *registro)
{


	printf("\nEscreva o novo registro numero %d \n",nreg+1);
	printf("Nome ");
	gets(registro->desc);
	gets(registro->desc);

	printf("escreva a quantidade atual ");
	scanf("%d",&registro->qtatual);
	printf("escreva a quantidade minima ");
	scanf("%d",&registro->qtmin);
	printf("escreva data de validade com DD/MM/AAAA ");
	gets(registro->datval);
	gets(registro->datval);

	p = fopen("produtos.txt","a");


	fwrite(&*registro,sizeof(*registro),1,p);
	fclose(p);
	add1total();


}


#ifndef VETOR_H
#define VETOR_H

class vetor
{
private:
    int * vet;
    int n;
    int tam;

public:
    vetor(int x);
    bool lervetor(int q);
    bool vazio();
    int imprimir();
    void uniao(vetor x, vetor y);
    void iguais(vetor x, vetor y);
    void subtracao(vetor x, vetor y);
    bool subconjunto(vetor x, vetor y);
    bool identico(vetor x, vetor y);
    bool disjunto(vetor x, vetor y);
    int apl(vetor x);
    int produtoescalar(vetor x, vetor y);
    void cres(vetor x);
    void desc(vetor x);
    void intercalar(vetor x, vetor y);
};



#endif // VETOR_H

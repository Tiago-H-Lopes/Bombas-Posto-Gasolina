#include <iostream>

using namespace std;

class BombaGasolina{
public:
    double Get();
    double Gasto(double litrosGastos);
    double ValorTotalPagar();
    void MudarPrecoLitro(double novoPreco);
    void EncherBomba(double quantidade);
    void EncherVeiculo(double quantidade);
    void ResetarValores();
    void MostrarGastosAtuais();

private:
    string nome;
    double litrosAtuais = 0, litrosGastos, precoLitro = 5.19;
    const int CAPACIDADE_MAXIMA = 500; //Litros
};
double BombaGasolina::Get(){
    return(litrosAtuais);
}
double BombaGasolina::Gasto(double litrosGastos2){
    litrosGastos = litrosGastos2;
    return(litrosAtuais-litrosGastos);
}
double BombaGasolina::ValorTotalPagar(){
    return(litrosGastos * precoLitro);
}
void BombaGasolina::MudarPrecoLitro(double novoPreco){
    precoLitro = novoPreco;
}
void BombaGasolina::EncherBomba(double quantidade){
    litrosAtuais += quantidade;
    if(litrosAtuais > CAPACIDADE_MAXIMA){
            cout << "Falha ao encher bomba, capacidade maxima excedida, favor inserir um valor menor" << endl;
            litrosAtuais -= quantidade;
    }else{cout << "Bomba enchida com sucesso!" << endl;}
}
void BombaGasolina::EncherVeiculo(double quantidade){
        litrosGastos = quantidade;
        litrosAtuais -= quantidade;
        if(litrosAtuais < 0){
            cout << "Quantidade de gasolina insuficiente na bomba" << endl;
        }else{
            cout << "Veiculo abastecido com sucesso!" << endl;
            Gasto(quantidade);
            MostrarGastosAtuais();
        }
}
void BombaGasolina::ResetarValores(){
    litrosAtuais = 0;
}
void BombaGasolina::MostrarGastosAtuais(){
    cout << "\nVoce encheu um total de " << litrosGastos << " litros";
    cout << "\nO preco atual da gasolina e de: R$" <<precoLitro;
    cout << "\nPortanto o total a ser pago e: R$" << ValorTotalPagar() << endl;
}
int main(){

    BombaGasolina bomba[4];
    int resposta, numero_bomba, resultado;
    double litros, precoLitro;

    cout << "\nBem vindo(a) ao programa para controle de bombas para postos de Gasolina!";
    do{
       cout << "\nO que voce deseja fazer ?"
       << "\n1 - Ver informacoes de todas as 4 bombas"
       << "\n2 - Ver as informacoes de uma bomba em especifico"
       << "\n3 - Encher um veiculo"
       << "\n4 - Encher uma das bombas"
       << "\n5 - Encher todas as bombas"
       << "\n6 - Zerar uma bomba manualmente"
       << "\n7 - Alterar preco da gasolina"
       << "\n8 - Sair"
       << "\nSua Resposta: ";
       cin >> resposta;
       system("cls");

        switch(resposta){
            case(1):
                for(int i=0; i<4; i++){
                cout << "\nBomba " << i+1 << " esta com " << bomba[i].Get() << " Litros atualmente" << endl;
                }
            break;
            case(2):
               cout << "\nDeseja ver informacoes sobre qual bomba ? ";
               cin >> numero_bomba;
               cout << "\nA bomba " << numero_bomba << " esta com " << bomba[numero_bomba-1].Get() << " Litros atualmente" << endl;
            break;
            case(3):
                cout << "\nO veiculo sera abastecido em qual bomba? ";
                cin >> numero_bomba;
                cout << "\nCom quantos litros o veiculo sera abastecido ? ";
                cin >> litros;
                bomba[numero_bomba-1].EncherVeiculo(litros);
            break;
            case(4):
                cout << "\nDeseja Encher qual bomba ? ";
                cin >> numero_bomba;
                cout << "\nCom quantos litros a bomba sera abastecida (somente numeros. ex: 2.5)? ";
                cin >> litros;
                bomba[numero_bomba-1].EncherBomba(litros);
            break;
            case(5):
                for(int i=0; i<4; i++){
                cout << "\nBomba " << i+1;
                cout << "\nCom quantos litros a bomba sera abastecida (somente numeros. ex: 2.5)? ";
                cin >> litros;
                bomba[i].EncherBomba(litros);
                }
            break;
            case(6):
                cout << "\nQual bomba voce deseja zerar a quantidade atual de gasolina armazenada ? ";
                cin >> numero_bomba;
                bomba[numero_bomba-1].ResetarValores();
                cout << "Bomba zerada com sucesso!" << endl;
            break;
            case(7):
                cout << "\nInforme o preco atual da gasolina: ";
                cin >> precoLitro;
                bomba[0].MudarPrecoLitro(precoLitro);
                bomba[1].MudarPrecoLitro(precoLitro);
                bomba[2].MudarPrecoLitro(precoLitro);
                bomba[3].MudarPrecoLitro(precoLitro);
                cout << "Preco alterado com sucesso!" << endl;
            break;
        }
    }while(resposta != 8);

return 0;
}

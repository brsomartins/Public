package br.com.brsomartins.gna;

public class Principal {

	public static void main(String[] args) {
		
		for (int i = 0; i < 100; i++) {
			System.out.println(geraNome() + " " + geraSobrenome());
		}
		
	}
	
	public static String geraNome() {
		String[] nomes = {"Jo�o", "Jos�", "Lu�s", "Carlos", "Breno", "Rafael", "Felipe", "Lucas",
						  "Caio", "M�rcio", "Guilherme", "Matheus", "Jorge", "F�bio", "Bruno",
						  "Gabriel", "Jaime", "Ricardo", "Pedro", "Paulo", "Eduardo", "Gerson",
						  "Igor", "Rian", "Renan", "Daniel", "Alan", "Ant�nio", "Marcos", "Augusto",
						  "C�sar", "Cassiano", "Dem�trio", "Cl�udio", "Diego", "Fernando", "Ed�lson",
						  "Fl�vio", "Frederico", "Henrique", "Gustavo", "Leonardo", "Jamil", "Jairo",
						  "Luan", "Lu�s", "Luciano", "Marcelo", "Marco", "M�rio", "N�lio", "Roberto",
						  "Peter", "Rodrigo", "Robson", "Thiago", "Vitor", "Vin�cius", "Renato"};
		String str = "";
		int qtdNomes = (int) (Math.random() * 100 + 1);
		
		if (qtdNomes > 20) { // 80% de chance de ser nome simples
			int i = (int) (Math.random() * nomes.length);
			str = nomes[i];
		}
		
		if (qtdNomes <= 20) { // 20% de chance de ser nome composto
			int i = (int) (Math.random() * nomes.length);
			int j = (int) (Math.random() * nomes.length);
			
			while (i == j) {
				j = (int) (Math.random() * nomes.length);
			}
			
			str = nomes[i] + " " + nomes[j];
		}
		
		return str;
	}
	
	public static String geraSobrenome() {
		String[] nomes = {"Silva", "Santos", "Lopes", "Mendes", "Martins", "Freitas", "Soares",
						  "Bastos", "da Silva", "dos Santos", "Mesquita", "Barros", "de Medeiros",
						  "Medeiros", "Teixeira", "Matos", "Gomes", "Rocha", "Fonseca", "Velasco",
						  "Cardoso", "Pires", "Barbosa", "Oliveira", "Viana", "Costa", "Ramalho",
						  "Pinho", "de Oliveira"};
		String str = "";
		int qtdNomes = (int) (Math.random() * 100 + 1);
		
		if (qtdNomes <= 5) { // 5% de chance de ter s� um sobrenome
			int i = (int) (Math.random() * nomes.length);
			str = nomes[i];
		}
		
		if ((qtdNomes > 5) && (qtdNomes <= 85)) { // 80% de chance de ter dois sobrenomes
			int i = (int) (Math.random() * nomes.length);
			int j = (int) (Math.random() * nomes.length);
			
			while (i == j) {
				j = (int) (Math.random() * nomes.length);
			}
		
			str = nomes[i] + " " + nomes[j];
		}
		
		if ((qtdNomes > 85) && (qtdNomes <= 95)) { // 10% de chance de ter tr�s sobrenomes
			int i = (int) (Math.random() * nomes.length);
			int j = (int) (Math.random() * nomes.length);
			int k = (int) (Math.random() * nomes.length);
			
			while ((i == j) || (j == k) || (k == i)) {
				
				while (i == j) {
					j = (int) (Math.random() * nomes.length);
				}
				
				while (j == k) {
					k = (int) (Math.random() * nomes.length);
				}
				
				while (k == i) {
					i = (int) (Math.random() * nomes.length);
				}
				
			}
			
			str = nomes[i] + " " + nomes[j] + " " + nomes[k];
		}
		
		if (qtdNomes > 95) { // 5% de chance de ter quatro sobrenomes
			int i = (int) (Math.random() * nomes.length);
			int j = (int) (Math.random() * nomes.length);
			int k = (int) (Math.random() * nomes.length);
			int l = (int) (Math.random() * nomes.length);
			
			while ((i == j) || (j == k) || (k == l) || (l == i)) {
				
				while (i == j) {
					j = (int) (Math.random() * nomes.length);
				}
				
				while (j == k) {
					k = (int) (Math.random() * nomes.length);
				}
				
				while (k == l) {
					l = (int) (Math.random() * nomes.length);
				}
				
				while (l == i) {
					i = (int) (Math.random() * nomes.length);
				}
				
			}
			
			str = nomes[i] + " " + nomes[j] + " " + nomes[k] + " " + nomes[l];
		}
		
		return str;
	}

}

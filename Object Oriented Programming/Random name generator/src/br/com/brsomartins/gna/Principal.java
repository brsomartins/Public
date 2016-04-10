package br.com.brsomartins.gna;

public class Principal {

	public static void main(String[] args) {
		
		for (int i = 0; i < 100; i++) {
			System.out.println(geraNome() + " " + geraSobrenome());
		}
		
	}
	
	public static String geraNome() {
		String[] nomes = {"João", "José", "Luís", "Carlos", "Breno", "Rafael", "Felipe", "Lucas",
						  "Caio", "Márcio", "Guilherme", "Matheus", "Jorge", "Fábio", "Bruno",
						  "Gabriel", "Jaime", "Ricardo", "Pedro", "Paulo", "Eduardo", "Gerson",
						  "Igor", "Rian", "Renan", "Daniel", "Alan", "Antônio", "Marcos", "Augusto",
						  "César", "Cassiano", "Demétrio", "Cláudio", "Diego", "Fernando", "Edílson",
						  "Flávio", "Frederico", "Henrique", "Gustavo", "Leonardo", "Jamil", "Jairo",
						  "Luan", "Luís", "Luciano", "Marcelo", "Marco", "Mário", "Nélio", "Roberto",
						  "Peter", "Rodrigo", "Robson", "Thiago", "Vitor", "Vinícius", "Renato"};
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
		
		if (qtdNomes <= 5) { // 5% de chance de ter só um sobrenome
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
		
		if ((qtdNomes > 85) && (qtdNomes <= 95)) { // 10% de chance de ter três sobrenomes
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

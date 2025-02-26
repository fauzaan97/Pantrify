#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm> // Tambahkan header ini

using namespace std;

// Struktur untuk menyimpan data resep
struct Resep {
    string nama;
    vector<string> bahan;
};

// Database resep sementara
vector<Resep> daftarResep = {
    {"Nasi Goreng", {"nasi", "telur", "kecap", "bawang"}},
    {"Omelette", {"telur", "keju", "garam"}},
    {"Sup Ayam", {"ayam", "wortel", "garam", "merica"}},
    {"Salad Buah", {"apel", "pisang", "yogurt"}}
};

// Fungsi untuk mencari resep berdasarkan bahan yang dimiliki pengguna
vector<string> cariResep(const vector<string>& bahanPengguna) {
    vector<string> hasil;
    
    for (const auto& resep : daftarResep) {
        for (const auto& bahan : bahanPengguna) {
            if (std::find(resep.bahan.begin(), resep.bahan.end(), bahan) != resep.bahan.end()) {
                hasil.push_back(resep.nama);
                break;
            }
        }
    }
    return hasil;
}

int main() {
    vector<string> bahanUser;
    string input;
    
    cout << "Masukkan bahan yang Anda miliki (ketik 'selesai' untuk mengakhiri):\n";
    while (true) {
        cin >> input;
        if (input == "selesai") break;
        bahanUser.push_back(input);
    }

    vector<string> rekomendasi = cariResep(bahanUser);
    
    if (!rekomendasi.empty()) {
        cout << "Resep yang dapat dibuat: \n";
        for (const auto& r : rekomendasi) {
            cout << "- " << r << endl;
        }
    } else {
        cout << "Maaf, tidak ada resep yang cocok dengan bahan yang Anda miliki." << endl;
    }
    
    return 0;
}
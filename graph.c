#include "graph.h"
#include <string.h>


int adj_list[MAX_NODES][MAX_NODES];
char node_names[MAX_NODES][20] = {
    "Dehradun", "Haridwar", "Rishikesh", "Mussoorie", "Haldwani", "Nainital", "Almora",
    "Pithoragarh", "Rudraprayag", "Kedarnath", "Badrinath", "Chamoli", "Uttarkashi",
    "Roorkee", "Kashipur", "Bageshwar", "Ranikhet", "Haldwani", "Pauri", "Tehri"
};  

double lat_lng[MAX_NODES][2] = {
    {30.3165, 78.0322}, {29.9457, 78.1689}, {30.0852, 78.2877}, {30.4597, 78.0695}, {29.2180, 79.5196},
    {29.3803, 79.4635}, {29.5990, 79.6419}, {29.5930, 80.2149}, {30.2854, 79.2761}, {30.7353, 79.0669},
    {30.7453, 79.4842}, {30.3988, 79.4351}, {30.7333, 78.4667}, {29.8544, 77.8887}, {29.2243, 78.9523},
    {29.8389, 79.7625}, {29.6483, 79.4330}, {29.2180, 79.5196}, {30.1540, 78.7777}, {30.3833, 78.4833}
};

void init_graph(void) {

    for (int i = 0; i < MAX_NODES; i++) {
        for (int j = 0; j < MAX_NODES; j++) {
            adj_list[i][j] = INF;
        }
        adj_list[i][i] = 0;  
    }
    // Garhwal region
    adj_list[0][1] = adj_list[1][0] = 50;   // Dehradun-Haridwar (NH34)
    adj_list[0][2] = adj_list[2][0] = 25;   // Dehradun-Rishikesh (NH7)
    adj_list[0][3] = adj_list[3][0] = 35;   // Dehradun-Mussoorie (Mussoorie Rd)
    adj_list[0][8] = adj_list[8][0] = 100;  // Dehradun-Rudraprayag (NH58)
    adj_list[1][2] = adj_list[2][1] = 20;   // Haridwar-Rishikesh (NH7)
    adj_list[1][13] = adj_list[13][1] = 30; // Haridwar-Roorkee (NH58)
    adj_list[2][12] = adj_list[12][2] = 80; // Rishikesh-Uttarkashi (hill rd)
    adj_list[3][19] = adj_list[19][3] = 60; // Mussoorie-Tehri (Tehri Rd)
    adj_list[8][11] = adj_list[11][8] = 90; // Rudraprayag-Chamoli (NH58)
    adj_list[11][10] = adj_list[10][11] = 50; // Chamoli-Badrinath (NH58)
    adj_list[11][9] = adj_list[9][11] = 80;   // Chamoli-Kedarnath (pilgrim rd)
    adj_list[18][19] = adj_list[19][18] = 70; // Pauri-Tehri (state rd)

    // Kumaon region
    adj_list[4][5] = adj_list[5][4] = 35;   // Haldwani-Nainital (NH109)
    adj_list[4][14] = adj_list[14][4] = 40; // Haldwani-Kashipur (NH9)
    adj_list[5][6] = adj_list[6][5] = 65;   // Nainital-Almora (NH109)
    adj_list[6][16] = adj_list[16][6] = 50; // Almora-Ranikhet (state rd)
    adj_list[6][15] = adj_list[15][6] = 70; // Almora-Bageshwar (NH9C)
    adj_list[7][15] = adj_list[15][7] = 100;// Pithoragarh-Bageshwar (NH9)

    // Inter-region (e.g., Dehradun to Kumaon via Roorkee/Kashipur)
    adj_list[0][13] = adj_list[13][0] = 70; // Dehradun-Roorkee (NH58)
    adj_list[13][14] = adj_list[14][13] = 50; // Roorkee-Kashipur (NH9)
    adj_list[14][4] = adj_list[4][14] = 60;   // Kashipur-Haldwani (NH9)
    adj_list[4][6] = adj_list[6][4] = 100;    // Haldwani-Almora (via Kaladhungi)

  
}


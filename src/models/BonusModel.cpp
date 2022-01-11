/**
 *  ╒══════════════════════════════════════╕
 *  │                                      │
 *  │             Doodle Jump              │
 *  │        Advanced Programming          │
 *  │                                      │
 *  │            Robbe Nooyens             │
 *  │    s0201010@student.uantwerpen.be    │
 *  │                                      │
 *  │        University of Antwerp         │
 *  │                                      │
 *  ╘══════════════════════════════════════╛
 */

#include "BonusModel.h"

models::JetpackModel::JetpackModel(): BonusModel() {

}

models::SpringModel::SpringModel(): BonusModel() {

}

models::BonusModel::BonusModel(): EntityModel() {

}

void models::BonusModel::update(double elapsed) {
}

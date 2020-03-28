#include <iostream>
#include <string>
#include <stdlib.h>     
#include <algorithm>
#include <vector>

using namespace std;

struct Proposal{
    string name;
    int numProps;
    float precio;
    vector<string> metReqs;
};

void printVect(vector<string> v);
void fillReqs(vector<string>&, int);
void fillProps(vector<Proposal>&, int);
vector <Proposal> checkCompliance(vector<Proposal>&);
vector <Proposal> checkLowestPrice(vector<Proposal>&);
Proposal theOne(vector<Proposal>&);

int main(){
    int numReqs, numProps;
    string reqAndProps;
    vector<string> requests;
    vector<Proposal> proposals;
    vector<Proposal> maxCompProps;
    vector<Proposal> lowestPriceComps;
    Proposal choosenProposal;
//------------------------RFP 1-----------------------------------------------------------//
    getline(cin, reqAndProps);
    numReqs = reqAndProps[0] - '0';
    numProps = reqAndProps[2] - '0'; 
    fillReqs(requests, numReqs);
    fillProps(proposals, numProps);
    maxCompProps = checkCompliance(proposals);
    lowestPriceComps = checkLowestPrice(maxCompProps);
    choosenProposal = theOne(lowestPriceComps); 
    cout << "RFP #1\n" << choosenProposal.name;
    cout << endl << endl;

//------------------------RFP 2-----------------------------------------------------------//
    getline(cin, reqAndProps);
    numReqs = reqAndProps[0] - '0';
    numProps = reqAndProps[2] - '0'; 
    requests.clear();
    proposals.clear();
    fillReqs(requests, numReqs);
    fillProps(proposals, numProps);
    maxCompProps = checkCompliance(proposals);
    lowestPriceComps = checkLowestPrice(maxCompProps);
    choosenProposal = theOne(lowestPriceComps); 
    cout <<"RFP #2\n" << choosenProposal.name;
    cout << endl << endl;
    
    return 0;
}

void printVect(vector<string> v){
    for(auto it : v){
        cout << it << '\n';
    }
}

void fillReqs(vector<string> &v, int numReqs){
    string request;
    for(int i = 0; i < numReqs; i++){
        getline(cin, request);
        v.push_back(request);
    }
}

void fillProps(vector<Proposal>& proposals, int numProps){
    string myStr;
    string price;
    Proposal proposal;
    for(int i = 0; i < numProps; i++){
        price = "";
        getline(cin, proposal.name);
        getline(cin, myStr);
        auto it = find(myStr.begin(), myStr.end(), ' '); it++;
        auto beg = myStr.begin();
        while(beg != it){
            price += *beg;
            beg++;
        }
        proposal.precio = stof(price);
        proposal.numProps = *it - '0';
        proposal.metReqs.clear();
        for(int j = 0; j < proposal.numProps; j++){
            getline(cin, myStr);
            proposal.metReqs.push_back(myStr);
        }
        proposals.push_back(proposal);
    }
}

vector <Proposal> checkCompliance(vector<Proposal>& proposals){
    int max = proposals[0].metReqs.size();
    vector <Proposal> maxCompProposals;
    for(int i = 1; i < proposals.size(); i++){
        if(max <= proposals[i].metReqs.size()){
            max = proposals[i].metReqs.size();
        }
    }
    for(int i = 0; i < proposals.size(); i++){
        if(max == proposals[i].metReqs.size()){
            maxCompProposals.push_back(proposals[i]);
        }
    }
    return maxCompProposals;
}

vector <Proposal> checkLowestPrice(vector<Proposal>& maxCompProposals){
    float min = maxCompProposals[0].precio;
    vector <Proposal> lowestPriceProps;
    for(int i = 1; i < maxCompProposals.size(); i++){
        if(min >= maxCompProposals[i].precio){
            min = maxCompProposals[i].precio;
        }
    } 
    for(int i = 0; i < maxCompProposals.size(); i++){
        if(min == maxCompProposals[i].precio){
            lowestPriceProps.push_back(maxCompProposals[i]);
        }
    }
    return lowestPriceProps;
}

Proposal theOne(vector<Proposal>& lowestPriceProps){
    return lowestPriceProps[0];
}



































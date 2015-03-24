clear all; %Sterge variabilele
fnm = input('Filename:'); %Introducerea numelui fisierului .. .ex: 'fisier.wav'

fin = fopen(fnm, 'r'); %Deschiderea fisierului 
object_number = fscanf(fin, '%d' , 1);
time = fscanf(fin, '%f' , 1);
tstep = fscanf(fin, '%f' , 1);

it=time/tstep;

A(2,it)=0;
B(2,it)=0;
for j = 1:it
    A(1,j)=fscanf(fin, '%f',1);
    A(2,j)=fscanf(fin, '%f',1);
    B(1,j)=fscanf(fin, '%f',1);
    B(2,j)=fscanf(fin, '%f',1);
end
plot(A(1,:),A(2,:),B(1,:),B(2,:));
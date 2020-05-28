#pragma once
class LibMat
{
public:
	LibMat();
	virtual ~LibMat();
	virtual void print() const;
};
void print(const LibMat& m);


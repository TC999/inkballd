//----- (01012C05) --------------------------------------------------------
Helpers::CLogBlock::CLogBlock(void* self, const char* name, int line)
{
    ((CLogBlock*)self)->line = line;
    ((CLogBlock*)self)->name = name;
}

Helpers::CLogBlock::CLogBlock(void* self, const char* name, int* context)
{
    ((CLogBlock*)self)->line = (int)(intptr_t)context;
    ((CLogBlock*)self)->name = name;
}
